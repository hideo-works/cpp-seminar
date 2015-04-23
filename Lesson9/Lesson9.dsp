# Microsoft Developer Studio Project File - Name="Lesson9" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Lesson9 - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "Lesson9.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "Lesson9.mak" CFG="Lesson9 - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "Lesson9 - Win32 Release" ("Win32 (x86) Console Application" 用)
!MESSAGE "Lesson9 - Win32 Debug" ("Win32 (x86) Console Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Lesson9 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I ".\src\\" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "Lesson9 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I ".\src\\" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Lesson9 - Win32 Release"
# Name "Lesson9 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "trump.cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\trump\Card.cpp
# End Source File
# Begin Source File

SOURCE=.\src\trump\Hand.cpp
# End Source File
# Begin Source File

SOURCE=.\src\trump\Joker.cpp
# End Source File
# Begin Source File

SOURCE=.\src\trump\Master.cpp
# End Source File
# Begin Source File

SOURCE=.\src\trump\Player.cpp
# End Source File
# Begin Source File

SOURCE=.\src\trump\Table.cpp
# End Source File
# End Group
# Begin Group "fantan.cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\fantan\Fantan.cpp
# End Source File
# Begin Source File

SOURCE=.\src\fantan\FantanMaster.cpp
# End Source File
# Begin Source File

SOURCE=.\src\fantan\FantanPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\src\fantan\FantanRule.cpp
# End Source File
# Begin Source File

SOURCE=.\src\fantan\FantanTable.cpp
# End Source File
# End Group
# Begin Group "oldmaid.cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\oldmaid\BackHand.cpp
# End Source File
# Begin Source File

SOURCE=.\src\oldmaid\OldMaid.cpp
# End Source File
# Begin Source File

SOURCE=.\src\oldmaid\OldMaidPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\src\oldmaid\OldMaidRule.cpp
# End Source File
# Begin Source File

SOURCE=.\src\oldmaid\OldMaidTable.cpp
# End Source File
# End Group
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "trump.h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\trump\Card.h
# End Source File
# Begin Source File

SOURCE=.\src\trump\Hand.h
# End Source File
# Begin Source File

SOURCE=.\src\trump\Joker.h
# End Source File
# Begin Source File

SOURCE=.\src\trump\Master.h
# End Source File
# Begin Source File

SOURCE=.\src\trump\Player.h
# End Source File
# Begin Source File

SOURCE=.\src\trump\Rule.h
# End Source File
# Begin Source File

SOURCE=.\src\trump\Table.h
# End Source File
# End Group
# Begin Group "fantan.h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\fantan\Fantan.h
# End Source File
# Begin Source File

SOURCE=.\src\fantan\FantanMaster.h
# End Source File
# Begin Source File

SOURCE=.\src\fantan\FantanPlayer.h
# End Source File
# Begin Source File

SOURCE=.\src\fantan\FantanRule.h
# End Source File
# Begin Source File

SOURCE=.\src\fantan\FantanTable.h
# End Source File
# End Group
# Begin Group "oldmaid.h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\oldmaid\BackHand.h
# End Source File
# Begin Source File

SOURCE=.\src\oldmaid\OldMaid.h
# End Source File
# Begin Source File

SOURCE=.\src\oldmaid\OldMaidPlayer.h
# End Source File
# Begin Source File

SOURCE=.\src\oldmaid\OldMaidRule.h
# End Source File
# Begin Source File

SOURCE=.\src\oldmaid\OldMaidTable.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\Executable.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
