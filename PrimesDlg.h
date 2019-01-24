// PrimesDlg.h : header file
//

#if !defined(AFX_PRIMESDLG_H__37810105_AD6D_4E7B_9A67_FD5DA0C54D32__INCLUDED_)
#define AFX_PRIMESDLG_H__37810105_AD6D_4E7B_9A67_FD5DA0C54D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TabDialogCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CPrimesDlg dialog

class CPrimesDlg : public CDialog
{
// Construction
public:
	CPrimesDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrimesDlg)
	enum { IDD = IDD_PRIMES_DIALOG };
	CTabDialogCtrl	m_cTab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrimesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrimesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIMESDLG_H__37810105_AD6D_4E7B_9A67_FD5DA0C54D32__INCLUDED_)
