// MillionTab.cpp : implementation file
//

#include "stdafx.h"
#include "Primes.h"
#include "MillionTab.h"
#include "ProgressDlg.h"

#include <fstream.h>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMillionTab dialog


CMillionTab::CMillionTab(CWnd* pParent /*=NULL*/)
	: CDialog(CMillionTab::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMillionTab)
	m_lMaxPrime = 1;
	m_sCurrent = _T("");
	//}}AFX_DATA_INIT
}


void CMillionTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMillionTab)
	DDX_Text(pDX, IDE_MAXPRIME, m_lMaxPrime);
	DDX_Text(pDX, IDE_CURRENT, m_sCurrent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMillionTab, CDialog)
	//{{AFX_MSG_MAP(CMillionTab)
	ON_BN_CLICKED(IDC_SOLVE, OnSolve)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMillionTab message handlers

UINT Million(LPVOID lpData)
{
	// SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));

	ofstream fout;

	bool Prime;
	long Number, Factor, FactorIndex;
	long NumPrimes, TotalPrimes;

	long Min, Max, MaxFactor, NumFactors = 0;
	long Maximum;

	long double Time = 0;

	int FileNumber = 0;

	char Summary[512];

	long *Primes;

	//Setup variables
	Min = 1;
	Max = 1000000;

	Maximum = g_lNumPrime;

	//Convert Maximum to millions
	Maximum *= 1000000; //Multiply by 1 million

	//Record the highest prime that needs to be stored
	long MaxPrime  = (long)sqrt(Maximum);

	//Find max array bounds (will always fit primes up to MaxPrime
	long ArraySize = (long)MaxPrime / 3 + 1;
	
	//Create the prime array
	Primes = new long[ArraySize];
	memset(Primes, 0, ArraySize * sizeof(long));

	Number = 0;

	TotalPrimes = 0;

	//Store program start time
	clock_t ProgramStart = clock();
	while (Number <= Maximum && bCalculatingPrimes)
	{				
		NumPrimes = 0; //Reset number of primes

		//Build file string
		char FileName[81];
		sprintf  (FileName, "Out%i.txt", FileNumber);
		fout.open(FileName);
		if (!fout)
		{
			sprintf(Summary, "\"%s\" could not be opened. It may be already in use or containing illegal charactars.", FileName);
			MessageBox((HWND)lpData, Summary, sMsgCaption, MB_ICONERROR);
			return 0;
		}

		//Handle "2"
		if (FileNumber == 0)
		{
			fout << 2 << endl;
			NumPrimes = 1;
			Min = 3;
		}

		//Store start time
		clock_t Start = clock();
		for (Number = Min; Number <= Max && bCalculatingPrimes; Number += 2)
		{
			Prime = true;					//The number is prime until it is proven unprime
			MaxFactor = int(sqrt(Number));	//A number is prime as long as it is not divisible by any primes less than MaxFactor
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

				fout << Number << endl;	//print the prime number to the file
				++NumPrimes;			//Increment the number of primes
			}
		}
		//Store the finish time
		clock_t Finish = clock();

		Time = double((Finish - Start))/CLOCKS_PER_SEC;

		//Append summary to file
		fout << "--------------------------Summary---------------------------" <<endl;
		fout << "Time: " << Time << " seconds"<<endl;
		fout << "Number of Primes: " << NumPrimes;
		
		//Close the file stream
		fout.close();

		//Display on screen summary
		sprintf(g_sMessage, "%s (%d - %d million) has %i primes in %.2f seconds", FileName, (Min-1)/1000000, Max/1000000, NumPrimes, Time);

		//Calculate new Min and Max for next million
		Min = FileNumber * 1000000 + 1000000 + 1;
		Max = Min + 1000000 - 1;

		//Add primes in current million to total
		TotalPrimes += NumPrimes;

		//Increment file name
		++FileNumber;
	}
	clock_t ProgramFinish = clock(); //eq time loop finished

	Time = double((ProgramFinish - ProgramStart))/CLOCKS_PER_SEC; //Get the tics (Finish-Start) then divide by CLOCKS_PER_SEC to get the time in seconds

	//Create status file and store overall summary
	fout.open("Stats.txt");
	fout << "Total Time Taken: " << Time << " seconds\n";
	fout << "Total Number of Primes: " << TotalPrimes << endl;
	fout.close();

	delete[] Primes;

	// SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));

	bCalculatingPrimes = false;

	//Send overall summary to screen
	sprintf(Summary, "Program Time - %f\nPrimes Found - %d", Time, TotalPrimes);
	MessageBox((HWND)lpData, Summary, sMsgCaption, 0);
	sprintf(g_sMessage, "Program Complete in %.2f seconds finding %d primes", Time, TotalPrimes);
	::EnableWindow((HWND)lpData, TRUE);

	return 1;
}

void CMillionTab::OnSolve() 
{
	if (UpdateData(TRUE))
	{
		g_sMessage[0] = NULL;
		g_lNumPrime = m_lMaxPrime;
		lTotal = m_lMaxPrime * 1000000;
		lDone = 0;

		bCalculatingPrimes = true;
		AfxBeginThread(Million, (HWND)hMainWnd, THREAD_PRIORITY_NORMAL);
		
		CProgressDlg dlg;
		dlg.DoModal();
	}
	else
		MessageBox("Please enter a file to output to.", sMsgCaption, MB_ICONERROR);
}
