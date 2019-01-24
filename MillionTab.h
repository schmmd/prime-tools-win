#if !defined(AFX_MILLIONTAB_H__F2AF59C5_89AF_4A89_9F8A_E708732CB9E9__INCLUDED_)
#define AFX_MILLIONTAB_H__F2AF59C5_89AF_4A89_9F8A_E708732CB9E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MillionTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMillionTab dialog

class CMillionTab : public CDialog
{
// Construction
public:
	CMillionTab(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMillionTab)
	enum { IDD = IDD_MILLION_TAB };
	long	m_lMaxPrime;
	CString	m_sCurrent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMillionTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMillionTab)
	afx_msg void OnSolve();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MILLIONTAB_H__F2AF59C5_89AF_4A89_9F8A_E708732CB9E9__INCLUDED_)
