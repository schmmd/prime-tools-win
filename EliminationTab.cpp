// EliminationTab.cpp : implementation file
//

#include "stdafx.h"
#include "Primes.h"
#include "EliminationTab.h"
#include "ProgressDlg.h"

#include <fstream.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEliminationTab dialog


CEliminationTab::CEliminationTab(CWnd* pParent /*=NULL*/)
	: CDialog(CEliminationTab::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEliminationTab)
	m_lMaxPrime = 2;
	m_sOutput = _T("Output.txt");
	//}}AFX_DATA_INIT
}


void CEliminationTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEliminationTab)
	DDX_Text(pDX, IDE_MAXPRIME, m_lMaxPrime);
	DDV_MinMaxLong(pDX, m_lMaxPrime, 2, 2147483647);
	DDX_Text(pDX, IDE_OUTPUT, m_sOutput);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEliminationTab, CDialog)
	//{{AFX_MSG_MAP(CEliminationTab)
	ON_BN_CLICKED(IDC_SOLVE, OnSolve)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEliminationTab message handlers

struct ITEM
{
	long Value;
	bool Prime;
};

UINT Elimination(LPVOID lpData)
{
	// SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));

	ofstream fout;

	long Number, Index, Multiple;
	long Num;

	long Min, Max, NumFactors = 0;

	long double Time = 0;

	char Summary[128];

	ITEM *Primes;
	
	Max = g_lNumPrime;
	Min = 2;

	fout.open(g_sOutput);
	if (!fout)
	{
		sprintf(Summary, "\"%s\" could not be opened. It may be already in use or containing illegal charactars.", g_sOutput);
		MessageBox((HWND)lpData, Summary, "Error", 0);
		return 0;
	}

	//Record start time
	clock_t BeginProgram = clock();

	//Message process
	sprintf(g_sMessage, "Creating array...");
	lTotal = Max - Min + 1; // +1 because it is inclusive with max

	//Record start time
	clock_t Start = clock();
	Primes = new ITEM[lTotal]; //Create primes array
	if (!Primes)
	{
		sprintf(Summary, "Not enough memory to hold %d 4 byte integer varibles\n    %d bytes\n    %.2f kb\n    %.2f mb\n", Max, Max*4, Max * 4.0 / 1024.0, Max * 4.0 / 1024.0 / 1024.0);
		MessageBox((HWND)lpData, Summary, "Error", 0);
		return 0;
	}

	// Message process
	sprintf(g_sMessage, "Filling array...");
	lDone  = 0;
	for (lDone = 0; lDone < lTotal && bCalculatingPrimes; ++lDone)      //Fill array (2 to Max)
	{
		Primes[lDone].Value = lDone + Min;
		Primes[lDone].Prime = true;
	}
	//Record finish time
	clock_t Finish = clock();

	//Message summary
	//cout<<"(" << double((Finish - Start))/CLOCKS_PER_SEC << " seconds) " << 4*Max << "b " << 4*Max/1000 << "kb " << 4*Max/1000000 << "mb\n";

	//Message process
	sprintf(g_sMessage, "Eliminating composites... (%% composite shown)");
	lDone = 0;
	Start = clock();
	for (Index = 0, Number = Primes[0].Value; Number <= sqrt(Max) && bCalculatingPrimes; ++Index, Number = Primes[Index].Value)
	{
		if (Primes[Index].Prime) //If isn't prime, all of the numbers that would be crossed out would already have been
		{
			for (Multiple = Number * 2; Multiple <= Max; Multiple += Number) //Get all multiples of current number
			{
				if (Primes[Multiple - Min].Prime)
				{
					Primes[Multiple - Min].Prime = false; //Multiple is not prime
					lDone++;
				}
			}
		}
	}
	Finish = clock(); //eq time loop finished
	//cout<<"(" << double((Finish - Start))/CLOCKS_PER_SEC << " seconds) " << Num << "\n";

	sprintf(g_sMessage, "Outputing primes...");
	lDone = 0;
	Num = 0;
	Start = clock();
	for (lDone = 0; lDone <= lTotal && bCalculatingPrimes; ++lDone)
	{
		if (Primes[lDone].Prime)
		{
			fout << Primes[lDone].Value << endl;
			++Num;
		}
	}
	Finish = clock();
	//cout<<"(" << double((Finish - Start))/CLOCKS_PER_SEC << " seconds) " << Num << "\n";

	clock_t EndProgram = clock();

	Time = double(EndProgram - BeginProgram)/CLOCKS_PER_SEC;

	//cout << "\nOperation Complete (" << double((EndProgram - BeginProgram))/CLOCKS_PER_SEC << " seconds)\n\n";
	fout << "--------------------------Summary---------------------------" << endl;
	fout << "Time: " << Time << " seconds"<<endl;
	fout << "Number of Primes: " << Num;

	fout.close(); //Close the fout

	delete[] Primes;

	// SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));

	bCalculatingPrimes = false;

	sprintf(Summary, "Time Taken - %f\nPrimes Found - %d", Time, Num);
	MessageBox((HWND)lpData, Summary, "Summary", 0);
	::EnableWindow((HWND)lpData, TRUE);

	return 1;
}

void CEliminationTab::OnSolve() 
{
	if (!bCalculatingPrimes && UpdateData(TRUE))
	{
		if (m_sOutput != "")
		{
			g_sMessage[0] = NULL;
			sprintf(g_sOutput, m_sOutput);
			g_lNumPrime = lTotal = m_lMaxPrime;
			lDone = 0;

			bCalculatingPrimes = true;
			AfxBeginThread(Elimination, (HWND)hMainWnd, THREAD_PRIORITY_NORMAL);
			
			CProgressDlg dlg;
			dlg.DoModal();
		}
		else
			MessageBox("Please enter a file to output to.", sMsgCaption, MB_ICONERROR);
	}
}

void CEliminationTab::OnBrowse() 
{
	UpdateData(TRUE);

	CFileDialog BrowseDialog(0, "*.*", "", OFN_LONGNAMES | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, "Text File (*.*)|*.*|", this);
	BrowseDialog.DoModal();

	m_sOutput = BrowseDialog.GetPathName();
	if (m_sOutput != "")
		UpdateData(FALSE);	
}
