// IsPrimeTab.cpp : implementation file
//

#include "stdafx.h"
#include "Primes.h"
#include "IsPrimeTab.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIsPrimeTab dialog


CIsPrimeTab::CIsPrimeTab(CWnd* pParent /*=NULL*/)
	: CDialog(CIsPrimeTab::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIsPrimeTab)
	m_sResult = _T("");
	m_lPrime = 0;
	//}}AFX_DATA_INIT
}


void CIsPrimeTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIsPrimeTab)
	DDX_Text(pDX, IDE_RESULT, m_sResult);
	DDX_Text(pDX, IDE_PRIME, m_lPrime);
	DDV_MinMaxLong(pDX, m_lPrime, 2, 2147483647);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIsPrimeTab, CDialog)
	//{{AFX_MSG_MAP(CIsPrimeTab)
	ON_BN_CLICKED(IDC_SOLVE, OnSolve)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIsPrimeTab message handlers

void CIsPrimeTab::OnSolve() 
{
	if (UpdateData(TRUE))
	{
		clock_t Start = clock();

		bool Prime = true;
		long Number = m_lPrime;
		long MaxFactor = (long)sqrt(Number);
		for (long Factor = 2; Factor <= MaxFactor && Prime; ++Factor) //Start dividing it by 2 - a half of itself
		{
			if (Number % Factor == 0) //if there is no remainder (modules if faster than division)
				Prime = false; //Number is not prime, loop will terminate because Prime = false
		}

		if (Number < 2)
			Prime = false;

		clock_t Finish = Start;
		double Time = double(Finish - Start) / CLOCKS_PER_SEC;

		char Summary[512];
		if (Prime)
			sprintf(Summary, "%d is prime in %.2f seconds.", Number, Time);
		else
			sprintf(Summary, "%d is divisible by %d in %.2f seconds.", Number, --Factor, Time);
		//MessageBox(Summary, "Summary");
		m_sResult = Summary;
		UpdateData(FALSE);
	}		
}
