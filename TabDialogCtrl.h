#if !defined(AFX_TABDIALOGCTRL_H__0015A5A3_1662_4D42_BC79_3009F20672F2__INCLUDED_)
#define AFX_TABDIALOGCTRL_H__0015A5A3_1662_4D42_BC79_3009F20672F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabDialogCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabDialogCtrl window

class CTabDialogCtrl : public CTabCtrl
{
// Construction
public:
	CTabDialogCtrl();

	CDialog *m_cDialog[5];
	int m_iCurrent;
	int m_nTabs;

// Attributes
public:

// Operations
public:
	void Init();
	void SetRectangle();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabDialogCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTabDialogCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTabDialogCtrl)
	afx_msg void OnSelchange(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDIALOGCTRL_H__0015A5A3_1662_4D42_BC79_3009F20672F2__INCLUDED_)
