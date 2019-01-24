// FirstTab.cpp : implementation file
//

#include "stdafx.h"
#include "Primes.h"
#include "FirstTab.h"
#include "ProgressDlg.h"

#include <fstream.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFirstTab dialog


CFirstTab::CFirstTab(CWnd* pParent /*=NULL*/)
	: CDialog(CFirstTab::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFirstTab)
	m_lNumPrime = 1;
	m_sOutput = _T("Output.txt");
	//}}AFX_DATA_INIT
}


void CFirstTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFirstTab)
	DDX_Text(pDX, IDE_NUMPRIME, m_lNumPrime);
	DDV_MinMaxLong(pDX, m_lNumPrime, 1, 2147483647);
	DDX_Text(pDX, IDE_OUTPUT, m_sOutput);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFirstTab, CDialog)
	//{{AFX_MSG_MAP(CFirstTab)
	ON_BN_CLICKED(IDC_SOLVE, OnSolve)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirstTab message handlers

UINT First(LPVOID lpData)
{
	//SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));

	ofstream fout;

	bool Prime;
	long Number, Factor, FactorIndex;
	long NumPrimes;

	long Min, MaxFactor;

	long MaxPrime = g_lNumPrime, NumFactors = 0;

	long double Time = 0;

	char Summary[512];

	long *Primes;

	//Find max array bounds (will always fit primes up to MaxPrime
	long ArraySize = (long)MaxPrime / 3 + 1;

	Primes = new long[ArraySize]; //Make Primes an array
	memset(Primes, 0, ArraySize * sizeof(long));

	fout.open(g_sOutput);
	if (!fout)
	{
		sprintf(Summary, "\"%s\" could not be opened. It may be already in use or containing illegal charactars.", g_sOutput);
		MessageBox((HWND)lpData, Summary, sMsgCaption, MB_ICONERROR);
		return 1;
	}

	//Handle "2"
	Min = 3;
	fout << 2 << endl;
	NumPrimes = 1;

	//Record start time
	clock_t Start = clock();

	for (Number = Min; NumPrimes < MaxPrime && bCalculatingPrimes; Number += 2)
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
			if (Number <= MaxPrime)
				Primes[NumFactors++] = Number; //Add 1 after because it first sets 0 to 3

			fout << Number << endl; //Output prime
			lDone = ++NumPrimes;
		}
	}

	//Record stop time
	clock_t Finish = clock();

	//Calculate time
	Time = double((Finish - Start))/CLOCKS_PER_SEC;

	//Append summary to file
	fout << "--------------------------Summary---------------------------" <<endl;
	fout << "Time: " << Time << " seconds" << endl;
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

void CFirstTab::OnSolve() 
{
	if (!bCalculatingPrimes && UpdateData(TRUE))
	{
		if (m_sOutput != "")
		{
			g_sMessage[0] = NULL;
			sprintf(g_sOutput, m_sOutput);
			g_lNumPrime = lTotal = m_lNumPrime;
			lDone = 0;

			bCalculatingPrimes = true;
			AfxBeginThread(First, (LPVOID)hMainWnd, THREAD_PRIORITY_NORMAL);
			
			CProgressDlg dlg;
			dlg.DoModal();
		}
		else
			MessageBox("Please enter a file to output to.", sMsgCaption, MB_ICONERROR);
	}
}

void CFirstTab::OnBrowse() 
{
	UpdateData(TRUE);

	CFileDialog BrowseDialog(0, "*.*", "", OFN_LONGNAMES | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, "Text File (*.*)|*.*|", this);
	BrowseDialog.DoModal();

	m_sOutput = BrowseDialog.GetPathName();
	if (m_sOutput != "")
		UpdateData(FALSE);			
}
