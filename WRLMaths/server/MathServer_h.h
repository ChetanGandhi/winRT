

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Jan 26 21:37:11 2015
 */
/* Compiler settings for C:\Users\chetan\AppData\Local\Temp\MathServer.idl-711eae4e:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __MathServer_h_h__
#define __MathServer_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ____x_ABI_CMathServer_CISquare_FWD_DEFINED__
#define ____x_ABI_CMathServer_CISquare_FWD_DEFINED__
typedef interface __x_ABI_CMathServer_CISquare __x_ABI_CMathServer_CISquare;

#ifdef __cplusplus
namespace ABI {
    namespace MathServer {
        interface ISquare;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CMathServer_CISquare_FWD_DEFINED__ */


#ifndef ____x_ABI_CMathServer_CICube_FWD_DEFINED__
#define ____x_ABI_CMathServer_CICube_FWD_DEFINED__
typedef interface __x_ABI_CMathServer_CICube __x_ABI_CMathServer_CICube;

#ifdef __cplusplus
namespace ABI {
    namespace MathServer {
        interface ICube;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CMathServer_CICube_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"
#include "Windows.Foundation.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_MathServer_0000_0000 */
/* [local] */ 



#ifdef __cplusplus
namespace ABI {
namespace MathServer {
class CMath;
} /*MathServer*/
}
#endif
#if !defined(____x_ABI_CMathServer_CISquare_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_MathServer_ISquare[] = L"MathServer.ISquare";
#endif /* !defined(____x_ABI_CMathServer_CISquare_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_MathServer_0000_0000 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_MathServer_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MathServer_0000_0000_v0_0_s_ifspec;

#ifndef ____x_ABI_CMathServer_CISquare_INTERFACE_DEFINED__
#define ____x_ABI_CMathServer_CISquare_INTERFACE_DEFINED__

/* interface __x_ABI_CMathServer_CISquare */
/* [uuid][object] */ 



/* interface ABI::MathServer::ISquare */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CMathServer_CISquare;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace MathServer {
            
            MIDL_INTERFACE("FC681092-D99E-4BF5-A1D1-177A2504154E")
            ISquare : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE SquareOfInteger( 
                    /* [in] */ int number,
                    /* [out][retval] */ int *square) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_ISquare = __uuidof(ISquare);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CMathServer_CISquareVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CMathServer_CISquare * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CMathServer_CISquare * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CMathServer_CISquare * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CMathServer_CISquare * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CMathServer_CISquare * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CMathServer_CISquare * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *SquareOfInteger )( 
            __x_ABI_CMathServer_CISquare * This,
            /* [in] */ int number,
            /* [out][retval] */ int *square);
        
        END_INTERFACE
    } __x_ABI_CMathServer_CISquareVtbl;

    interface __x_ABI_CMathServer_CISquare
    {
        CONST_VTBL struct __x_ABI_CMathServer_CISquareVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CMathServer_CISquare_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CMathServer_CISquare_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CMathServer_CISquare_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CMathServer_CISquare_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CMathServer_CISquare_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CMathServer_CISquare_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CMathServer_CISquare_SquareOfInteger(This,number,square)	\
    ( (This)->lpVtbl -> SquareOfInteger(This,number,square) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CMathServer_CISquare_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_MathServer_0000_0001 */
/* [local] */ 

#if !defined(____x_ABI_CMathServer_CICube_INTERFACE_DEFINED__)
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_MathServer_ICube[] = L"MathServer.ICube";
#endif /* !defined(____x_ABI_CMathServer_CICube_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_MathServer_0000_0001 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_MathServer_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MathServer_0000_0001_v0_0_s_ifspec;

#ifndef ____x_ABI_CMathServer_CICube_INTERFACE_DEFINED__
#define ____x_ABI_CMathServer_CICube_INTERFACE_DEFINED__

/* interface __x_ABI_CMathServer_CICube */
/* [uuid][object] */ 



/* interface ABI::MathServer::ICube */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CMathServer_CICube;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace MathServer {
            
            MIDL_INTERFACE("4E8D9D98-4F78-4250-A860-F4AC04C5D30E")
            ICube : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE CubeOfInteger( 
                    /* [in] */ int number,
                    /* [out][retval] */ int *cube) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_ICube = __uuidof(ICube);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CMathServer_CICubeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CMathServer_CICube * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CMathServer_CICube * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CMathServer_CICube * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CMathServer_CICube * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CMathServer_CICube * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CMathServer_CICube * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *CubeOfInteger )( 
            __x_ABI_CMathServer_CICube * This,
            /* [in] */ int number,
            /* [out][retval] */ int *cube);
        
        END_INTERFACE
    } __x_ABI_CMathServer_CICubeVtbl;

    interface __x_ABI_CMathServer_CICube
    {
        CONST_VTBL struct __x_ABI_CMathServer_CICubeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CMathServer_CICube_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CMathServer_CICube_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CMathServer_CICube_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CMathServer_CICube_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CMathServer_CICube_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CMathServer_CICube_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CMathServer_CICube_CubeOfInteger(This,number,cube)	\
    ( (This)->lpVtbl -> CubeOfInteger(This,number,cube) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CMathServer_CICube_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_MathServer_0000_0002 */
/* [local] */ 

#ifndef RUNTIMECLASS_MathServer_CMath_DEFINED
#define RUNTIMECLASS_MathServer_CMath_DEFINED
extern const __declspec(selectany) _Null_terminated_ WCHAR RuntimeClass_MathServer_CMath[] = L"MathServer.CMath";
#endif


/* interface __MIDL_itf_MathServer_0000_0002 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_MathServer_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_MathServer_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


