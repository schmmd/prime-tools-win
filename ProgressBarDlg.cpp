// ProgressBarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Primes.h"
#include "ProgressBarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressBarDlg dialog


CProgressBarDlg::CProgressBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressBarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgressBarDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CProgressBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressBarDlg)
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgressBarDlg, CDialog)
	//{{AFX_MSG_MAP(CProgressBarDlg)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressBarDlg message handlers

void CProgressBarDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_Progress.SetPos(lDone>>4);
	UpdateData(FALSE);

	if (!bCalculatingPrimes)
		DestroyWindow();
	
	CDialog::OnTimer(nIDEvent);
}

BOOL CProgressBarDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_Progress.SetRange32(0, lTotal>>4);
	UpdateData(FALSE);
	SetTimer(1, 25, NULL);
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProgressBarDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	bCalculatingPrimes = 0;
	DestroyWindow();
	
	CDialog::OnClose();
}

BOOL CProgressBarDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	// ::EnableWindow(hMainWnd, TRUE);
	
	return CDialog::DestroyWindow();
}
