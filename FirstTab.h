#if !defined(AFX_FIRSTTAB_H__604FF682_CAD4_4D61_AC8F_B9F4B91A279F__INCLUDED_)
#define AFX_FIRSTTAB_H__604FF682_CAD4_4D61_AC8F_B9F4B91A279F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FirstTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFirstTab dialog

class CFirstTab : public CDialog
{
// Construction
public:
	CFirstTab(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFirstTab)
	enum { IDD = IDD_FIRST_TAB };
	long	m_lNumPrime;
	CString	m_sOutput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFirstTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFirstTab)
	afx_msg void OnSolve();
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIRSTTAB_H__604FF682_CAD4_4D61_AC8F_B9F4B91A279F__INCLUDED_)
