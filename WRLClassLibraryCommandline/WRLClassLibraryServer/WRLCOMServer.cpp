//include wrl.h before WRLCOMServer_h.h
#include <wrl.h>
#include "WRLCOMServer_h.h"

using namespace Microsoft::WRL;

namespace ABI
{
	namespace WRLCOMServer
	{
		class CSumSubtract:public RuntimeClass<ISum, ISubtract> //<-- meaning?
		{
			InspectableClass(L"WRLCOMServer.CSumSubtract", BaseTrust) //No ";" as this is expansion macro
			//<-- meaning?

			public:
				CSumSubtract()
				{}

				HRESULT __stdcall SumOfTwoInteger(int numberOne, int numberTwo, int *psum) 
				{
					*psum = numberOne + numberTwo;
					return S_OK;
				}

				HRESULT __stdcall SubtractionOfTwoInteger(int numberOne, int numberTwo, int *psubtract)
				{
					*psubtract = numberOne - numberTwo;
					return S_OK;
				}
		};

		ActivatableClass(CSumSubtract); //<-- meaning?
	}
}

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason)
	{
		case DLL_PROCESS_ATTACH:
			break;

		case DLL_THREAD_ATTACH:
			break;

		case DLL_THREAD_DETACH:
			break;

		case DLL_PROCESS_DETACH:
			break;
	}

	return(TRUE);
}


#pragma comment(linker, "/EXPORT:DllGetClassObject=_DllGetClassObject@12,PRIVATE")
#pragma comment(linker, "/EXPORT:DllCanUnloadNow=_DllCanUnloadNow@0,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetActivationFactory=_DllGetActivationFactory@8,PRIVATE")

/* x64
#pragma comment(linker, "/EXPORT:DllGetClassObject,PRIVATE")
#pragma comment(linker, "/EXPORT:DllCanUnloadNow,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetActivationFactory,PRIVATE")
*/

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();

	// As modul is reference.
	return(module.GetClassObject(rclsid, riid, ppv));
}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();

	if (module.GetObjectCount() == 0)
	{
		return S_OK;
	}
	
	return S_FALSE;
}

//SAL <--meanning?
extern "C" HRESULT __stdcall DllGetActivationFactory(HSTRING activatableClassId, IActivationFactory **ppFactory)
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return(module.GetActivationFactory(activatableClassId, ppFactory));
}
