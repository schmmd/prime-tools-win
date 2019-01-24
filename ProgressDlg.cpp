// ProgressDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Primes.h"
#include "ProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog


CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgressDlg)
	//}}AFX_DATA_INIT

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgressDlg)
	DDX_Control(pDX, IDE_REPORT, m_sReport);
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
	//{{AFX_MSG_MAP(CProgressDlg)
	ON_WM_TIMER()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg message handlers

void CProgressDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//char sTemp[64];
	//sprintf(sTemp, "%d/%d", lDone, lTotal);
	CString sTemp;

	if (m_lRange != lTotal >> 4 && m_lRange != -1)
	{
		m_lRange = lTotal >> 4;
		m_Progress.SetRange32(0, m_lRange);
	}

	m_Progress.SetPos(lDone>>4);

	m_sReport.GetWindowText(sTemp);
	if (g_sMessage != sTemp)
		m_sReport.SetWindowText(g_sMessage);

	if (!bCalculatingPrimes)
		EndDialog(1);
	
	CDialog::OnTimer(nIDEvent);
}

BOOL CProgressDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_sReport.SetWindowText("");
	
	// TODO: Add extra initialization here
	if (lTotal>>4 != lDone>>4)
	{
		m_lRange = lTotal >> 4;
		m_Progress.SetRange32(0, m_lRange);
		m_Progress.SetPos    (lDone>>4);
	}
	else
	{
		m_lRange = -1;
		m_Progress.SetRange32(0, 1);
		m_Progress.SetPos    (1);
	}
	UpdateData(FALSE);

	SetTimer(1, 10, NULL);

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CProgressDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));

	if (bCalculatingPrimes)
	{
		MessageBox("Primes calculation interrupted.");
		bCalculatingPrimes = false;
	}
	
	return CDialog::DestroyWindow();
}

BOOL CProgressDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
	// return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
