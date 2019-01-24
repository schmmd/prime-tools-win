// TabDialogCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Primes.h"
#include "TabDialogCtrl.h"

#include "PrimeTab.h"
#include "FirstTab.h"
#include "MillionTab.h"
#include "IsPrimeTab.h"
#include "EliminationTab.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabDialogCtrl

CTabDialogCtrl::CTabDialogCtrl()
{
	m_cDialog[0]=new CFirstTab;
	m_cDialog[1]=new CPrimeTab;
	m_cDialog[2]=new CMillionTab;
	m_cDialog[3]=new CEliminationTab;
	m_cDialog[4]=new CIsPrimeTab;

	m_nTabs = 5;
}

CTabDialogCtrl::~CTabDialogCtrl()
{
	for(int nCount=0; nCount < m_nTabs; nCount++){
		delete m_cDialog[nCount];
	}
}

void CTabDialogCtrl::Init()
{
	m_iCurrent=0;

	m_cDialog[0]->Create(IDD_FIRST_TAB,       this);
	m_cDialog[1]->Create(IDD_PRIME_TAB,       this);
	m_cDialog[2]->Create(IDD_MILLION_TAB,     this);
	m_cDialog[3]->Create(IDD_ELIMINATION_TAB, this);
	m_cDialog[4]->Create(IDD_ISPRIME_TAB,     this);

	m_cDialog[0]->ShowWindow(SW_SHOW);
	m_cDialog[1]->ShowWindow(SW_HIDE);
	m_cDialog[2]->ShowWindow(SW_HIDE);
	m_cDialog[3]->ShowWindow(SW_HIDE);
	m_cDialog[4]->ShowWindow(SW_HIDE);

	SetRectangle();
}

void CTabDialogCtrl::SetRectangle()
{
	CRect tabRect, itemRect;
	int nX, nY, nXc, nYc;

	GetClientRect(&tabRect);
	GetItemRect(0, &itemRect);

	nX  = itemRect.left;
	nY  = itemRect.bottom + 1;
	nXc = tabRect.right  - nX - 1;
	nYc = tabRect.bottom - nY - 1;

	m_cDialog[0]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_SHOWWINDOW);
	for(int nCount=1; nCount < m_nTabs; nCount++){
		m_cDialog[nCount]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_HIDEWINDOW);
	}
}


BEGIN_MESSAGE_MAP(CTabDialogCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CTabDialogCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabDialogCtrl message handlers

void CTabDialogCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_cDialog[m_iCurrent]->ShowWindow(SW_HIDE);
	m_iCurrent = GetCurSel();
	m_cDialog[m_iCurrent]->ShowWindow(SW_SHOW);
	m_cDialog[m_iCurrent]->SetFocus();
	
	*pResult = 0;
}
