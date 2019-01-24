#if !defined(AFX_ELIMINATIONTAB_H__1FC55271_24B5_48C7_8543_095239C7AE21__INCLUDED_)
#define AFX_ELIMINATIONTAB_H__1FC55271_24B5_48C7_8543_095239C7AE21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EliminationTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEliminationTab dialog

class CEliminationTab : public CDialog
{
// Construction
public:
	CEliminationTab(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEliminationTab)
	enum { IDD = IDD_ELIMINATION_TAB };
	long	m_lMaxPrime;
	CString	m_sOutput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEliminationTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEliminationTab)
	afx_msg void OnSolve();
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELIMINATIONTAB_H__1FC55271_24B5_48C7_8543_095239C7AE21__INCLUDED_)
