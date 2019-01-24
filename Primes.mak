# Microsoft Developer Studio Generated NMAKE File, Based on Primes.dsp
!IF "$(CFG)" == ""
CFG=Primes - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Primes - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Primes - Win32 Release" && "$(CFG)" != "Primes - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Primes.mak" CFG="Primes - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Primes - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Primes - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Primes - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Primes.exe"


CLEAN :
	-@erase "$(INTDIR)\EliminationTab.obj"
	-@erase "$(INTDIR)\FirstTab.obj"
	-@erase "$(INTDIR)\IsPrimeTab.obj"
	-@erase "$(INTDIR)\MillionTab.obj"
	-@erase "$(INTDIR)\Primes.obj"
	-@erase "$(INTDIR)\Primes.pch"
	-@erase "$(INTDIR)\Primes.res"
	-@erase "$(INTDIR)\PrimesDlg.obj"
	-@erase "$(INTDIR)\PrimeTab.obj"
	-@erase "$(INTDIR)\ProgressDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TabDialogCtrl.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Primes.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Primes.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Primes.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Primes.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Primes.pdb" /machine:I386 /out:"$(OUTDIR)\Primes.exe" 
LINK32_OBJS= \
	"$(INTDIR)\EliminationTab.obj" \
	"$(INTDIR)\FirstTab.obj" \
	"$(INTDIR)\IsPrimeTab.obj" \
	"$(INTDIR)\MillionTab.obj" \
	"$(INTDIR)\Primes.obj" \
	"$(INTDIR)\PrimesDlg.obj" \
	"$(INTDIR)\PrimeTab.obj" \
	"$(INTDIR)\ProgressDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TabDialogCtrl.obj" \
	"$(INTDIR)\Primes.res"

"$(OUTDIR)\Primes.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Primes - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Primes.exe"


CLEAN :
	-@erase "$(INTDIR)\EliminationTab.obj"
	-@erase "$(INTDIR)\FirstTab.obj"
	-@erase "$(INTDIR)\IsPrimeTab.obj"
	-@erase "$(INTDIR)\MillionTab.obj"
	-@erase "$(INTDIR)\Primes.obj"
	-@erase "$(INTDIR)\Primes.pch"
	-@erase "$(INTDIR)\Primes.res"
	-@erase "$(INTDIR)\PrimesDlg.obj"
	-@erase "$(INTDIR)\PrimeTab.obj"
	-@erase "$(INTDIR)\ProgressDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TabDialogCtrl.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Primes.exe"
	-@erase "$(OUTDIR)\Primes.ilk"
	-@erase "$(OUTDIR)\Primes.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Primes.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Primes.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Primes.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Primes.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Primes.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\EliminationTab.obj" \
	"$(INTDIR)\FirstTab.obj" \
	"$(INTDIR)\IsPrimeTab.obj" \
	"$(INTDIR)\MillionTab.obj" \
	"$(INTDIR)\Primes.obj" \
	"$(INTDIR)\PrimesDlg.obj" \
	"$(INTDIR)\PrimeTab.obj" \
	"$(INTDIR)\ProgressDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TabDialogCtrl.obj" \
	"$(INTDIR)\Primes.res"

"$(OUTDIR)\Primes.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Primes.dep")
!INCLUDE "Primes.dep"
!ELSE 
!MESSAGE Warning: cannot find "Primes.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Primes - Win32 Release" || "$(CFG)" == "Primes - Win32 Debug"
SOURCE=.\EliminationTab.cpp

"$(INTDIR)\EliminationTab.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"


SOURCE=.\FirstTab.cpp

"$(INTDIR)\FirstTab.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"


SOURCE=.\IsPrimeTab.cpp

"$(INTDIR)\IsPrimeTab.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"


SOURCE=.\MillionTab.cpp

"$(INTDIR)\MillionTab.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"


SOURCE=.\Primes.cpp

"$(INTDIR)\Primes.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"


SOURCE=.\Primes.rc

"$(INTDIR)\Primes.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PrimesDlg.cpp

"$(INTDIR)\PrimesDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"


SOURCE=.\PrimeTab.cpp

"$(INTDIR)\PrimeTab.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"


SOURCE=.\ProgressDlg.cpp

"$(INTDIR)\ProgressDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Primes - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Primes.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Primes.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Primes - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Primes.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Primes.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TabDialogCtrl.cpp

"$(INTDIR)\TabDialogCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Primes.pch"



!ENDIF 

