// stdafx.cpp : source file that includes just the standard includes
//	Primes.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

//CFileDialog BrowseDialog(0, "*.*", "", OFN_LONGNAMES | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, "Text File (*.*)|*.*|", NULL);
bool bCalculatingPrimes = 0;
long lDone = 0, lTotal = 0;
HWND hMainWnd = NULL;

const char* sMsgCaption = "Primes 1.0.0";

char g_sOutput[128];
long g_lNumPrime;
char g_sMessage[128];