// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A956E9E1_A3D5_4C2C_91B8_4D61FB1B1A92__INCLUDED_)
#define AFX_STDAFX_H__A956E9E1_A3D5_4C2C_91B8_4D61FB1B1A92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//extern CFileDialog BrowseDialog;

UINT PeekAndPumpThread(LPVOID pParam);

extern bool bCalculatingPrimes;
extern long lDone, lTotal;
extern HWND hMainWnd;

extern char g_sOutput[128];
extern long g_lNumPrime;
extern char g_sMessage[128];

extern const char* sMsgCaption;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A956E9E1_A3D5_4C2C_91B8_4D61FB1B1A92__INCLUDED_)
