// Primes.h : main header file for the PRIMES application
//

#if !defined(AFX_PRIMES_H__1F379D2D_D992_42FB_945C_DCFE32E3761E__INCLUDED_)
#define AFX_PRIMES_H__1F379D2D_D992_42FB_945C_DCFE32E3761E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrimesApp:
// See Primes.cpp for the implementation of this class
//

class CPrimesApp : public CWinApp
{
public:
	CPrimesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrimesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrimesApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIMES_H__1F379D2D_D992_42FB_945C_DCFE32E3761E__INCLUDED_)
