

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Apr 17 15:41:38 2014
 */
/* Compiler settings for TestComLibrary.idl:
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

#ifndef __TestComLibrary_i_h__
#define __TestComLibrary_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITestAction_FWD_DEFINED__
#define __ITestAction_FWD_DEFINED__
typedef interface ITestAction ITestAction;

#endif 	/* __ITestAction_FWD_DEFINED__ */


#ifndef __IAggregAtion_FWD_DEFINED__
#define __IAggregAtion_FWD_DEFINED__
typedef interface IAggregAtion IAggregAtion;

#endif 	/* __IAggregAtion_FWD_DEFINED__ */


#ifndef __TestAction_FWD_DEFINED__
#define __TestAction_FWD_DEFINED__

#ifdef __cplusplus
typedef class TestAction TestAction;
#else
typedef struct TestAction TestAction;
#endif /* __cplusplus */

#endif 	/* __TestAction_FWD_DEFINED__ */


#ifndef __AggregAtion_FWD_DEFINED__
#define __AggregAtion_FWD_DEFINED__

#ifdef __cplusplus
typedef class AggregAtion AggregAtion;
#else
typedef struct AggregAtion AggregAtion;
#endif /* __cplusplus */

#endif 	/* __AggregAtion_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITestAction_INTERFACE_DEFINED__
#define __ITestAction_INTERFACE_DEFINED__

/* interface ITestAction */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITestAction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("543370AB-CA7B-4D43-A3F5-55B15CCF7BA2")
    ITestAction : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TestAdd( 
            int a,
            int b) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITestActionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITestAction * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITestAction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITestAction * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITestAction * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITestAction * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITestAction * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITestAction * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TestAdd )( 
            ITestAction * This,
            int a,
            int b);
        
        END_INTERFACE
    } ITestActionVtbl;

    interface ITestAction
    {
        CONST_VTBL struct ITestActionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestAction_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITestAction_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITestAction_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITestAction_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITestAction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITestAction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITestAction_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITestAction_TestAdd(This,a,b)	\
    ( (This)->lpVtbl -> TestAdd(This,a,b) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITestAction_INTERFACE_DEFINED__ */


#ifndef __IAggregAtion_INTERFACE_DEFINED__
#define __IAggregAtion_INTERFACE_DEFINED__

/* interface IAggregAtion */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAggregAtion;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1FC1840A-5FAC-4112-864C-D366D7E2B3C1")
    IAggregAtion : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IAggregAtionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAggregAtion * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAggregAtion * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAggregAtion * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAggregAtion * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAggregAtion * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAggregAtion * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAggregAtion * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IAggregAtionVtbl;

    interface IAggregAtion
    {
        CONST_VTBL struct IAggregAtionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAggregAtion_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAggregAtion_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAggregAtion_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAggregAtion_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAggregAtion_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAggregAtion_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAggregAtion_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAggregAtion_INTERFACE_DEFINED__ */



#ifndef __TestComLibraryLib_LIBRARY_DEFINED__
#define __TestComLibraryLib_LIBRARY_DEFINED__

/* library TestComLibraryLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TestComLibraryLib;

EXTERN_C const CLSID CLSID_TestAction;

#ifdef __cplusplus

class DECLSPEC_UUID("400DB0F9-BB41-4ACD-A4EB-2219019F4F28")
TestAction;
#endif

EXTERN_C const CLSID CLSID_AggregAtion;

#ifdef __cplusplus

class DECLSPEC_UUID("1EA64394-4F7F-4DD2-A015-48F8C3D86D0F")
AggregAtion;
#endif
#endif /* __TestComLibraryLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


