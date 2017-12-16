#include <wrl.h> // for all WRL related

// created by midl, hence midl must run first than the cpp compiler and linker
#include "WRLCOMServer_h.h" // for ISum and ISubtract

using namespace Microsoft::WRL; // for all WRL related

// coclass definition
namespace ABI
{
	namespace WRLCOMServer
	{
		class CSumSubtract : public RuntimeClass<ISum, ISubtract>
		{
			InspectableClass(L"WRLCOMServer.CSumSubtract", BaseTrust)

		public:
			// constructor
			CSumSubtract()
			{
			}

			// ISum method implementation
			HRESULT __stdcall SumOfTwoIntegers(int num1, int num2, int *pSum)
			{
				// code
				*pSum = num1 + num2;
				return(S_OK);
			}

			// ISubtract method implementation
			HRESULT __stdcall SubtractionOfTwoIntegers(int num1, int num2, int *pSub)
			{
				// code
				*pSub = num1 - num2;
				return(S_OK);
			}
		};

		ActivatableClass(CSumSubtract);
	}
}

// for x86
#pragma comment(linker, "/EXPORT:DllGetClassObject=_DllGetClassObject@12,PRIVATE")
#pragma comment(linker, "/EXPORT:DllCanUnloadNow=_DllCanUnloadNow@0,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetActivationFactory=_DllGetActivationFactory@8,PRIVATE")

// for arm or x64
/*
#pragma comment(linker, "/EXPORT:DllGetClassObject,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetActivationFactory,PRIVATE")
#pragma comment(linker, "/EXPORT:DllCanUnloadNow,PRIVATE")
*/

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	// code
	switch (dwReason)
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

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid,  LPVOID *ppv)
{
	// code
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return(module.GetClassObject(rclsid, riid, ppv));
}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	// code
	const auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	if (module.GetObjectCount() == 0)
		return(S_OK);
	else
		return(S_FALSE);
}

extern "C" HRESULT __stdcall DllGetActivationFactory(HSTRING activatibleClassId, IActivationFactory** factory)
{
	// code
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return(module.GetActivationFactory(activatibleClassId, factory));
}
