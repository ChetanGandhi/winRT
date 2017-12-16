//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                WRL BASED COM SERVER
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

*** Creating Proxy/Stub Source Code Files, WinMD File From IDL File :
=====================================================================

midlrt.exe 
WRLCOMServer.idl
/metadata_dir "C:\Program Files (x86)\Windows Kits\8.1\References\CommonConfiguration\Neutral" 
/winrt 
/ns_prefix 
/h "WRLCOMServer_h.h" 
/winmd "WRLCOMServer.winmd" 

MIDL Compiler Complete Command In One Line :
--------------------------------------------
> midlrt.exe WRLCOMServer.idl /metadata_dir "C:\Program Files (x86)\Windows Kits\8.1\References\CommonConfiguration\Neutral" /winrt /ns_prefix /h "WRLCOMServer_h.h" /winmd "WRLCOMServer.winmd"

*********************************************************************************************************************
*********************************************************************************************************************

*** Merging Platform WinMD And Server WinMD File :
==================================================

mdmerge 
-metadata_dir "C:\Program Files (x86)\Windows Kits\8.1\References\CommonConfiguration\Neutral" 
-o:.\Temporary 
-i:. 
-v 
-partial

MDMERGE Complete Command In One Line :
======================================
> mdmerge /metadata_dir "C:\Program Files (x86)\Windows Kits\8.1\References\CommonConfiguration\Neutral" /o:.\Temporary /i:. /v /partial
  [ It Creates Our Specified "Temporary" Directory If Not Already Present And Then Copies Resultant WinMD To It ]

> Now Copy Newly Created WinMD File From .\Temporary Subdirectory To Current Directory To Override The Original One.

*********************************************************************************************************************
*********************************************************************************************************************

*** Compiling Server Source Code CPP File :
===========================================

cl.exe 
/c 
/EHsc 
/AI"C:\Program Files (x86)\Windows Kits\8.1\References\CommonConfiguration\Neutral" 
/D WINAPI_PARTITION_APP 
/D _USRDLL 
WRLCOMServer.cpp

CPP Compiler Complete Command In One Line :
===========================================
cl.exe /c /EHsc /AI"C:\Program Files (x86)\Windows Kits\8.1\References\CommonConfiguration\Neutral" /D WINAPI_PARTITION_APP /D _USRDLL WRLCOMServer.cpp

*********************************************************************************************************************
*********************************************************************************************************************

*** Linking The Obj File To Create Final Server DLL :
=====================================================

link.exe 
WRLCOMServer.obj 
/OUT:WRLCOMServer.dll 
runtimeobject.lib user32.lib kernel32.lib 
/SUBSYSTEM:CONSOLE 
/APPCONTAINER 
/MACHINE:X86 
/DLL

Linker Complete Command In One Line
===================================
link.exe WRLCOMServer.obj /OUT:WRLCOMServer.dll runtimeobject.lib user32.lib kernel32.lib /SUBSYSTEM:CONSOLE /APPCONTAINER /MACHINE:X86 /DLL

*********************************************************************************************************************
*********************************************************************************************************************

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                      CLIENT OF ABOVE WRL BASED COM SERVER
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

01) Create An Empty Directory Say 'WRLCOMClient'.

02) Copy Existing "Assets" Directory ( Along With Its Contents, i.e. Logos And Splash Images )
    To This Directory.

03) Copy Existing AppxManifest.xml File To This Directory.

04) Copy Above Server's Dll And WinMD Files Say, WRLCOMServer.dll And WRLCOMServer.winmd Files
    To This Directory.

05) Edit Above File In Editor And Make Relevant Changes :
    a) Create And Write New GUID ( Using GuidGen.exe Or By VS-IDE > Tools > Create GUID )
    b) Replace All Occurances Of Some Other Project Name By Our Desired Name Say 'WRLCOMClient'
    c) Keep Other Things Intact.

06) Create And Write WRLCOMClient.cpp File :
    - Add Server WinMD File By #using 
    - Then Add Server namespace By 'using'
    - Use COM Server Functionality As Necessary

07) Open "Developer Command Prompt for VS2013" And 'cd' To This 'WRLCOMClient" Directory.

08) Compile WRLCOMClient.cpp File By Following Command Line :
    
    cl.exe /c /ZW /EHsc WRLCOMClient.cpp

09) Link The Resultant .obj File By Following Command :

    cl.exe /MD WRLCOMClient.obj /link /APPCONTAINER RuntimeObject.lib /SUBSYSTEM:Windows

10) After Creating Exe Successfully, Now Create A Directory Named Say "MyPackage" Inside This Same Directory 
    And Put Following Files Into That.
    a) "Assets" Folder : Cofirm Path Of Images In AppxManifest.xml And Names Of Images Kept Here Are Matching.
    b) Above "exe" File
    c) AppxManifest.xml File
    d) COM Server's WinMD File
    e) COM Server's Dll File

11) To Craete App Package :

    MakeAppx pack /d .\MyPackage /p WRLCOMClient.appx

    [ WRLCOMClient.appx Package Will Be Craeted In The Current Directory ( Not Inside "MyPackage" Directory )

*** Assuming We Already Have Trusted Signing Certificate In Root Store And Client Certificate In Personal Store.
    This Is Confirmed By "dir Cert:\CurrentUser\My" Command And By "CertMgr.mmc".

12) Continuing From "11", Assuming We Have Copied "Thumbprint Number" To Certify Our App, Give Following Command :

    signtool sign /fd sha256 /sha1 <thumbprint number> WRLCOMClient.appx

06) To Allow Our Appx File To Get Installed Correctly, The Certificate MUST Be Trusted By "Local Machine" Too. To This ...

    - In File Explorer, right-click on the app package, and in the pop-up context menu select "Properties".
    - In the "Properties" dialog, select the "Digital Signatures" tab.
    - In the Signature list, select the signature and then click the "Details" button.
    - In the "Digital Signature Details" dialog, click the "View Certificate" button.
    - In the Certificate dialog, click the "Install Certificate" button.
    - In the Certificate Import Wizard, select "Local Machine" and then click "Next". You will need to grant administrator privileges to continue.
    - Select "Place all certificates in the following store" and browse to the "Trusted People" store and click to select it.
    - Click "Next", then click Finish to complete the wizard.Explorer, Right Click

07) Go To PwerShell Again, Open It In "Run As Administrative" Mode, Go To Above Path Of Our WRLCOMClient.appx File 
    ( If Path Contains Spaces, Enclose Whole Path In Pair Double Quotes ) And Install The Package To Mtro UI By :

    Add-AppxPackage .\WRLCOMClient.appx
