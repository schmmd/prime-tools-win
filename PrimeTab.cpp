// PrimeTab.cpp : implementation file
//

#include "stdafx.h"
#include "Primes.h"
#include "PrimeTab.h"
#include "ProgressDlg.h"

#include <fstream.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrimeTab dialog


CPrimeTab::CPrimeTab(CWnd* pParent /*=NULL*/)
	: CDialog(CPrimeTab::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrimeTab)
	m_sOutput = _T("Output.txt");
	m_lMaxPrime = 2;
	//}}AFX_DATA_INIT
}


void CPrimeTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrimeTab)
	DDX_Text(pDX, IDE_OUTPUT, m_sOutput);
	DDX_Text(pDX, IDE_MAXPRIME, m_lMaxPrime);
	DDV_MinMaxLong(pDX, m_lMaxPrime, 2, 2147483647);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrimeTab, CDialog)
	//{{AFX_MSG_MAP(CPrimeTab)
	ON_BN_CLICKED(IDC_SOLVE, OnSolve)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrimeTab message handlers

UINT Prime(LPVOID lpData)
{
	// SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));

	ofstream fout;

	bool Prime;
	long Number, Factor, FactorIndex;
	long NumPrimes;

	long Min, Max, MaxFactor, NumFactors = 0;

	long double Time = 0;

	char Summary[512];

	long *Primes;

	Max  = g_lNumPrime;
	Min  = 3;

	//Record the highest prime that needs to be stored
	long MaxPrime  = (long)sqrt(Max);

	//Find max array bounds (will always fit primes up to MaxPrime
	long ArraySize = (long)MaxPrime / 3 + 1;

	//Make Primes an array
	Primes = new long[ArraySize];
	memset(Primes, 0, sizeof(long) * ArraySize);

	fout.open(g_sOutput);
	if (!fout)
	{
		sprintf(Summary, "\"%s\" could not be opened. It may be already in use or containing illegal charactars.", g_sOutput);
		MessageBox((HWND)lpData, Summary, sMsgCaption, MB_ICONERROR);
		return 0;
	}

	//Handle prime "2"
	NumPrimes = 1;
	fout << 2 << endl;

	//Send message
	cout<<"\nSolving for primes... ";

	//Record start time
	clock_t Start = clock();

	for (Number = Min; Number <= Max && bCalculatingPrimes; Number += 2)
	{
		Prime = true;					//The number is prime until it is proven unprime
		MaxFactor = long(sqrt(Number));	//A number is prime as long as it is not divisible by any primes less than MaxFactor

		for (Factor = Primes[0], FactorIndex = 0; Factor <= MaxFactor && Prime && Factor; Factor = Primes[++FactorIndex])
		{
			if (Number % Factor == 0) //if there is no remainder (modules if faster than division)
				Prime = false; //Number is not prime, loop will terminate because Prime = false
		}

		if (Prime)
		{
			if (Number <= MaxPrime) //If we need to store it to use as a factor
				Primes[NumFactors++] = Number; //Store it

			lDone = Number;

			fout << Number << endl; //Output prime
			++NumPrimes;
		}
	}

	//Record stop time
	clock_t Finish = clock();

	//Calculate time
	Time = double((Finish - Start))/CLOCKS_PER_SEC;

	//Append summary to file
	fout << "--------------------------Summary---------------------------" <<endl;
	fout << "Time: " << Time << " seconds"<<endl;
	fout << "Number of Primes: " << NumPrimes <<"\n\n\n";

	//Close the file stream
	fout.close();

	delete[] Primes;

	// SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));

	bCalculatingPrimes = false;

	//Report summary
	sprintf(Summary, "Program Time - %.2f seconds\nPrimes Found - %d\n", Time, NumPrimes);
	MessageBox((HWND)lpData, Summary, sMsgCaption, 0);
	::EnableWindow((HWND)lpData, TRUE);

	return 1;
}

void CPrimeTab::OnSolve() 
{
	if (UpdateData(TRUE))
	{
		if (m_sOutput != "")
		{
			g_sMessage[0] = NULL;
			sprintf(g_sOutput, m_sOutput);
			g_lNumPrime = lTotal = m_lMaxPrime;
			lDone = 0;

			bCalculatingPrimes = true;
			AfxBeginThread(Prime, (HWND)hMainWnd, THREAD_PRIORITY_NORMAL);
			
			CProgressDlg dlg;
			dlg.DoModal();
		}
		else
			MessageBox("Please enter a file to output to.");
	}	
}

void CPrimeTab::OnBrowse() 
{
	UpdateData(TRUE);

	CFileDialog BrowseDialog(0, "*.*", "", OFN_LONGNAMES | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, "Text File (*.*)|*.*|", this);
	BrowseDialog.DoModal();

	m_sOutput = BrowseDialog.GetPathName();
	if (m_sOutput != "")
		UpdateData(FALSE);		
}
