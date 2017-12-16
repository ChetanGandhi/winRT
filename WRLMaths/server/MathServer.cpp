//include wrl.h before WRLMathServer_h.h 
#include <wrl.h>
#include "MathServer_h.h"

using namespace Microsoft::WRL;

namespace ABI
{
	namespace MathServer
	{
		class CMath: public RuntimeClass<ISquare, ICube>
		{
			InspectableClass(L"MathServer.CMath", BaseTrust)

			public:
				CMath()
				{}

				HRESULT __stdcall SquareOfInteger(int number, int *square)
				{
					*square = number * number;
					return S_OK;
				}

				HRESULT __stdcall CubeOfInteger(int number, int *cube)
				{
					*cube = number * number * number;
					return S_OK;
				}
		};

		ActivatableClass(CMath);
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

	return TRUE;
}

#pragma comment(linker, "/EXPORT:DllGetClassObject=_DllGetClassObject@12,PRIVATE")
#pragma comment(linker, "/EXPORT:DllCanUnloadNow=_DllCanUnloadNow@0,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetActivationFactory=_DllGetActivationFactory@8,PRIVATE")

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return module.GetClassObject(rclsid, riid, ppv);
}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return (module.GetObjectCount() == 0) ? S_OK : S_FALSE;
}

extern "C" HRESULT __stdcall DllGetActivationFactory(HSTRING activatableClassId, IActivationFactory **ppFactory)
{
	auto &module = Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule();
	return module.GetActivationFactory(activatableClassId, ppFactory);
}
