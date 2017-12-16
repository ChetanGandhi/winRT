// Compine and link
// cl.exe /c /ZW /EHsc HelloWorldCPPCx.cpp
// link.exe HelloWorldCPPCx.obj vccorlib.lib runtimeobject.lib /SUBSYSTEM:Console
//

#include<iostream>

using namespace std;
using namespace Platform;

int main(Array<String ^> ^arg)
{
	String ^str = "Hello Worl, C++/Cx ! \nC++ with Component Extention.";
	wcout<<str->Data()<<endl;
	return 0;
} 
