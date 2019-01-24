#if !defined(AFX_PROGRESSBARDLG_H__FA25726F_8052_40A0_8191_C1916907276A__INCLUDED_)
#define AFX_PROGRESSBARDLG_H__FA25726F_8052_40A0_8191_C1916907276A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProgressBarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressBarDlg dialog

class CProgressBarDlg : public CDialog
{
// Construction
public:
	CProgressBarDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProgressBarDlg)
	enum { IDD = IDD_PROGRESS };
	CProgressCtrl	m_Progress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressBarDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CProgressBarDlg)
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSBARDLG_H__FA25726F_8052_40A0_8191_C1916907276A__INCLUDED_)
