#if !defined(AFX_PRIMETAB_H__6580160F_32CB_4351_BD3B_42241E216FD6__INCLUDED_)
#define AFX_PRIMETAB_H__6580160F_32CB_4351_BD3B_42241E216FD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrimeTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrimeTab dialog

class CPrimeTab : public CDialog
{
// Construction
public:
	CPrimeTab(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrimeTab)
	enum { IDD = IDD_PRIME_TAB };
	CString	m_sOutput;
	long	m_lMaxPrime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrimeTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrimeTab)
	afx_msg void OnSolve();
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIMETAB_H__6580160F_32CB_4351_BD3B_42241E216FD6__INCLUDED_)
