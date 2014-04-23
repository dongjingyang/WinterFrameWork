

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Apr 10 15:19:44 2014
 */
/* Compiler settings for SimpleAttrCom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

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

#ifndef __SimpleAttrCom_h__
#define __SimpleAttrCom_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISimpleAttrCom_FWD_DEFINED__
#define __ISimpleAttrCom_FWD_DEFINED__
typedef interface ISimpleAttrCom ISimpleAttrCom;
#endif 	/* __ISimpleAttrCom_FWD_DEFINED__ */


#ifndef __IWComImpl_FWD_DEFINED__
#define __IWComImpl_FWD_DEFINED__
typedef interface IWComImpl IWComImpl;
#endif 	/* __IWComImpl_FWD_DEFINED__ */


#ifndef __CSimpleAttrComCom_FWD_DEFINED__
#define __CSimpleAttrComCom_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSimpleAttrComCom CSimpleAttrComCom;
#else
typedef struct CSimpleAttrComCom CSimpleAttrComCom;
#endif /* __cplusplus */

#endif 	/* __CSimpleAttrComCom_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISimpleAttrCom_INTERFACE_DEFINED__
#define __ISimpleAttrCom_INTERFACE_DEFINED__

/* interface ISimpleAttrCom */
/* [uuid][dual][object] */ 


EXTERN_C const IID IID_ISimpleAttrCom;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C2CD1DC-4B13-431e-B4CF-B0BABF76BFA7")
    ISimpleAttrCom : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TestAdd( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleAttrComVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleAttrCom * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleAttrCom * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleAttrCom * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISimpleAttrCom * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISimpleAttrCom * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISimpleAttrCom * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISimpleAttrCom * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TestAdd )( 
            ISimpleAttrCom * This);
        
        END_INTERFACE
    } ISimpleAttrComVtbl;

    interface ISimpleAttrCom
    {
        CONST_VTBL struct ISimpleAttrComVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleAttrCom_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleAttrCom_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleAttrCom_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISimpleAttrCom_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISimpleAttrCom_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISimpleAttrCom_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISimpleAttrCom_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISimpleAttrCom_TestAdd(This)	\
    ( (This)->lpVtbl -> TestAdd(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimpleAttrCom_INTERFACE_DEFINED__ */


#ifndef __IWComImpl_INTERFACE_DEFINED__
#define __IWComImpl_INTERFACE_DEFINED__

/* interface IWComImpl */
/* [uuid][dual][object] */ 


EXTERN_C const IID IID_IWComImpl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B53220A-C679-4c42-A3B1-C3A432216B25")
    IWComImpl : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Test1( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWComImplVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWComImpl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWComImpl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWComImpl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWComImpl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWComImpl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWComImpl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWComImpl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Test1 )( 
            IWComImpl * This);
        
        END_INTERFACE
    } IWComImplVtbl;

    interface IWComImpl
    {
        CONST_VTBL struct IWComImplVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWComImpl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWComImpl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWComImpl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWComImpl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWComImpl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWComImpl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWComImpl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWComImpl_Test1(This)	\
    ( (This)->lpVtbl -> Test1(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWComImpl_INTERFACE_DEFINED__ */



#ifndef __SimpleAttrCom_LIBRARY_DEFINED__
#define __SimpleAttrCom_LIBRARY_DEFINED__

/* library SimpleAttrCom */
/* [uuid][version] */ 


EXTERN_C const IID LIBID_SimpleAttrCom;

EXTERN_C const CLSID CLSID_CSimpleAttrComCom;

#ifdef __cplusplus

class DECLSPEC_UUID("4ED3625F-9551-4cc0-81DA-864418A01D2D")
CSimpleAttrComCom;
#endif
#endif /* __SimpleAttrCom_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


