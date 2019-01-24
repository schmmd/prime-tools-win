; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPrimesDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Primes.h"

ClassCount=10
Class1=CPrimesApp
Class2=CPrimesDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_FIRST_TAB
Resource2=IDR_MAINFRAME
Class4=CTabDialogCtrl
Resource3=IDD_ELIMINATION_TAB
Resource4=IDD_ABOUTBOX
Resource5=IDD_MILLION_TAB
Resource6=IDD_PRIME_TAB
Resource7=IDD_PRIMES_DIALOG
Class5=CPrimeTab
Class6=CMillionTab
Class7=CIsPrimeTab
Class8=CFirstTab
Class9=CEliminationTab
Resource8=IDD_ISPRIME_TAB
Class10=CProgressDlg
Resource9=IDD_PROGRESS

[CLS:CPrimesApp]
Type=0
HeaderFile=Primes.h
ImplementationFile=Primes.cpp
Filter=N
LastObject=CPrimesApp

[CLS:CPrimesDlg]
Type=0
HeaderFile=PrimesDlg.h
ImplementationFile=PrimesDlg.cpp
Filter=D
LastObject=CPrimesDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PrimesDlg.h
ImplementationFile=PrimesDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PRIMES_DIALOG]
Type=1
Class=CPrimesDlg
ControlCount=1
Control1=IDC_TAB,SysTabControl32,1342177280

[CLS:CTabDialogCtrl]
Type=0
HeaderFile=TabDialogCtrl.h
ImplementationFile=TabDialogCtrl.cpp
BaseClass=CTabCtrl
Filter=W
VirtualFilter=UWC
LastObject=CTabDialogCtrl

[DLG:IDD_ELIMINATION_TAB]
Type=1
Class=CEliminationTab
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDE_MAXPRIME,edit,1350639744
Control3=IDC_SOLVE,button,1342242817
Control4=IDC_STATIC,static,1342308353
Control5=IDS_OUTPUT,static,1342308352
Control6=IDE_OUTPUT,edit,1350631552
Control7=IDC_BROWSE,button,1342242816

[DLG:IDD_MILLION_TAB]
Type=1
Class=CMillionTab
ControlCount=6
Control1=IDS_STATIC,static,1342308352
Control2=IDE_MAXPRIME,edit,1350639744
Control3=IDS_MILLION,static,1342308352
Control4=IDC_SOLVE,button,1342242817
Control5=IDC_STATIC,static,1342308353
Control6=IDE_CURRENT,edit,1342244993

[DLG:IDD_FIRST_TAB]
Type=1
Class=CFirstTab
ControlCount=8
Control1=IDS_PRIMES,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDE_NUMPRIME,edit,1350639744
Control4=IDC_SOLVE,button,1342242817
Control5=IDC_STATIC,static,1342308353
Control6=IDS_OUTPUT,static,1342308352
Control7=IDE_OUTPUT,edit,1350631552
Control8=IDC_BROWSE,button,1342242816

[DLG:IDD_ISPRIME_TAB]
Type=1
Class=CIsPrimeTab
ControlCount=6
Control1=IDS_PRIMES,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDE_PRIME,edit,1350639744
Control4=IDC_SOLVE,button,1342242817
Control5=IDC_STATIC,static,1342308353
Control6=IDE_RESULT,edit,1342244993

[DLG:IDD_PRIME_TAB]
Type=1
Class=CPrimeTab
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDE_MAXPRIME,edit,1350639744
Control3=IDC_SOLVE,button,1342242817
Control4=IDC_STATIC,static,1342308353
Control5=IDS_OUTPUT,static,1342308352
Control6=IDE_OUTPUT,edit,1350631552
Control7=IDC_BROWSE,button,1342242816

[CLS:CPrimeTab]
Type=0
HeaderFile=PrimeTab.h
ImplementationFile=PrimeTab.cpp
BaseClass=CDialog
Filter=D
LastObject=IDE_MAXPRIME
VirtualFilter=dWC

[CLS:CMillionTab]
Type=0
HeaderFile=MillionTab.h
ImplementationFile=MillionTab.cpp
BaseClass=CDialog
Filter=D
LastObject=CMillionTab
VirtualFilter=dWC

[CLS:CFirstTab]
Type=0
HeaderFile=FirstTab.h
ImplementationFile=FirstTab.cpp
BaseClass=CDialog
Filter=D
LastObject=CFirstTab
VirtualFilter=dWC

[CLS:CEliminationTab]
Type=0
HeaderFile=EliminationTab.h
ImplementationFile=EliminationTab.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEliminationTab

[CLS:CIsPrimeTab]
Type=0
HeaderFile=IsPrimeTab.h
ImplementationFile=IsPrimeTab.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDE_RESULT

[DLG:IDD_PROGRESS]
Type=1
Class=CProgressDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PROGRESS,msctls_progress32,1350565888
Control3=IDE_REPORT,static,1342308352

[CLS:CProgressDlg]
Type=0
HeaderFile=ProgressDlg.h
ImplementationFile=ProgressDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CProgressDlg
VirtualFilter=dWC

