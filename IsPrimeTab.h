#if !defined(AFX_ISPRIMETAB_H__2C90C6F5_F5DC_459F_87DC_0CD62C552428__INCLUDED_)
#define AFX_ISPRIMETAB_H__2C90C6F5_F5DC_459F_87DC_0CD62C552428__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IsPrimeTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIsPrimeTab dialog

class CIsPrimeTab : public CDialog
{
// Construction
public:
	CIsPrimeTab(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIsPrimeTab)
	enum { IDD = IDD_ISPRIME_TAB };
	CString	m_sResult;
	COleCurrency	m_cPrime;
	long	m_lPrime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIsPrimeTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIsPrimeTab)
	afx_msg void OnSolve();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ISPRIMETAB_H__2C90C6F5_F5DC_459F_87DC_0CD62C552428__INCLUDED_)
