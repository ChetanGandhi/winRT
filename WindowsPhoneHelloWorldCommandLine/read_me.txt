3. Compile

csc.exe /nowarn:1701,1702,2008 /target:library /out:helloWorld.dll /preferreduilang:en-US /platform:anycpu HelloWorld.cs /reference:Microsoft.Phone.dll /reference:System.Windows.dll /reference:Windows.winmd

4. Create Package

Create folder "MyPackage"
Create "in" and "out" folder in "MyPackage"

Copy "AppManifest.xml" "WMAppManifest.xml" and "dll" to "in" folder

 cd C:\Program Files (x86)\Microsoft SDKs\Windows Phone\v8.0\Tools\MDILXAPCompile\
 MDILXAPCompile.exe /in:<"in" folder path> /out:<"out" folder path> /config:MDILXapCompileInput.xml

5.

Copy "coocked dll" from "out" folder to "MyPackage" folder.
Copy "Assets" folder to "MyPackage" folder.

Select all files excluding "in" and "out" folder.
Right click and "send to"->"Zip"

Rename this zip file. e.g. "HelloWorld.xap"
extation should be "xap" only.

6. Sign the package
cd ..
i.e. cd C:\Program Files (x86)\Microsoft SDKs\Windows Phone\v8.0\Tools

cd XapSignTool

XapSignTool.exe sign <path of xap file>

Use PowerShell if not able to do with Developer Commandprompt.

7.
cd ..
i.e cd C:\Program Files (x86)\Microsoft SDKs\Windows Phone\v8.0\Tools

cd "XAP Deployment"

XapDeployCmd.exe /installlaunch <signed xap file path> /targetdevice:xd 

xd: Default simulator

