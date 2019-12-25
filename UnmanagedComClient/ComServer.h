

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for ComServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
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
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ComServer_h__
#define __ComServer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IStringTests_FWD_DEFINED__
#define __IStringTests_FWD_DEFINED__
typedef interface IStringTests IStringTests;

#endif 	/* __IStringTests_FWD_DEFINED__ */


#ifndef __StringTests_FWD_DEFINED__
#define __StringTests_FWD_DEFINED__

#ifdef __cplusplus
typedef class StringTests StringTests;
#else
typedef struct StringTests StringTests;
#endif /* __cplusplus */

#endif 	/* __StringTests_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "hstring.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IStringTests_INTERFACE_DEFINED__
#define __IStringTests_INTERFACE_DEFINED__

/* interface IStringTests */
/* [object][helpstring][oleautomation][uuid] */ 


EXTERN_C const IID IID_IStringTests;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6F6B348B-CA71-4CF5-8F51-2CD2928273CB")
    IStringTests : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBstrFromComServer( 
            /* [retval][out] */ BSTR *returnValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLPStrFromComServer( 
            /* [retval][out] */ LPSTR *returnvalue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLPWStrFromComServer( 
            /* [retval][out] */ LPWSTR *returnvalue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLPUTF8StrFromComServer( 
            /* [retval][out] */ LPSTR *returnvalue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PassInBstr( 
            /* [in] */ BSTR bStr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PassInLPStr( 
            /* [in] */ LPSTR lpstr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PassInLPWStr( 
            /* [in] */ LPWSTR lpwstr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PassInLPUTF8Str( 
            /* [in] */ const CHAR *lputf8str) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PassInByRefBstr( 
            /* [out][in] */ BSTR *bStr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PassInByRefLPStr( 
            /* [out][in] */ LPSTR *lpstr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PassInByRefLPWStr( 
            /* [out][in] */ LPWSTR *lpwstr) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PassInByRefLPUTF8Str( 
            /* [out][in] */ LPSTR *lputf8str) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReverseBstr( 
            /* [in] */ BSTR bStr,
            /* [retval][out] */ BSTR *returnValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReverseLPStr( 
            /* [in] */ LPSTR lpstr,
            /* [retval][out] */ LPSTR *returnvalue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReverseLPWStr( 
            /* [in] */ LPWSTR lpwstr,
            /* [retval][out] */ LPWSTR *returnvalue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReverseLPUTF8Str( 
            /* [in] */ LPSTR lpstr,
            /* [retval][out] */ LPSTR *returnvalue) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStringTestsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStringTests * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStringTests * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStringTests * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBstrFromComServer )( 
            IStringTests * This,
            /* [retval][out] */ BSTR *returnValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLPStrFromComServer )( 
            IStringTests * This,
            /* [retval][out] */ LPSTR *returnvalue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLPWStrFromComServer )( 
            IStringTests * This,
            /* [retval][out] */ LPWSTR *returnvalue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLPUTF8StrFromComServer )( 
            IStringTests * This,
            /* [retval][out] */ CHAR *returnvalue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PassInBstr )( 
            IStringTests * This,
            /* [in] */ BSTR bStr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PassInLPStr )( 
            IStringTests * This,
            /* [in] */ LPSTR lpstr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PassInLPWStr )( 
            IStringTests * This,
            /* [in] */ LPWSTR lpwstr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PassInLPUTF8Str )( 
            IStringTests * This,
            /* [in] */ const CHAR *lputf8str);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PassInByRefBstr )( 
            IStringTests * This,
            /* [out][in] */ BSTR *bStr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PassInByRefLPStr )( 
            IStringTests * This,
            /* [out][in] */ LPSTR *lpstr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PassInByRefLPWStr )( 
            IStringTests * This,
            /* [out][in] */ LPWSTR *lpwstr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PassInByRefLPUTF8Str )( 
            IStringTests * This,
            /* [out][in] */ CHAR *lputf8str);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReverseBstr )( 
            IStringTests * This,
            /* [in] */ BSTR bStr,
            /* [retval][out] */ BSTR *returnValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReverseLPStr )( 
            IStringTests * This,
            /* [in] */ LPSTR lpstr,
            /* [retval][out] */ LPSTR *returnvalue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReverseLPWStr )( 
            IStringTests * This,
            /* [in] */ LPWSTR lpwstr,
            /* [retval][out] */ LPWSTR *returnvalue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReverseLPUTF8Str )( 
            IStringTests * This,
            /* [in] */ const CHAR *lpstr,
            /* [retval][out] */ CHAR *returnvalue);
        
        END_INTERFACE
    } IStringTestsVtbl;

    interface IStringTests
    {
        CONST_VTBL struct IStringTestsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStringTests_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStringTests_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStringTests_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStringTests_GetBstrFromComServer(This,returnValue)	\
    ( (This)->lpVtbl -> GetBstrFromComServer(This,returnValue) ) 

#define IStringTests_GetLPStrFromComServer(This,returnvalue)	\
    ( (This)->lpVtbl -> GetLPStrFromComServer(This,returnvalue) ) 

#define IStringTests_GetLPWStrFromComServer(This,returnvalue)	\
    ( (This)->lpVtbl -> GetLPWStrFromComServer(This,returnvalue) ) 

#define IStringTests_GetLPUTF8StrFromComServer(This,returnvalue)	\
    ( (This)->lpVtbl -> GetLPUTF8StrFromComServer(This,returnvalue) ) 

#define IStringTests_PassInBstr(This,bStr)	\
    ( (This)->lpVtbl -> PassInBstr(This,bStr) ) 

#define IStringTests_PassInLPStr(This,lpstr)	\
    ( (This)->lpVtbl -> PassInLPStr(This,lpstr) ) 

#define IStringTests_PassInLPWStr(This,lpwstr)	\
    ( (This)->lpVtbl -> PassInLPWStr(This,lpwstr) ) 

#define IStringTests_PassInLPUTF8Str(This,lputf8str)	\
    ( (This)->lpVtbl -> PassInLPUTF8Str(This,lputf8str) ) 

#define IStringTests_PassInByRefBstr(This,bStr)	\
    ( (This)->lpVtbl -> PassInByRefBstr(This,bStr) ) 

#define IStringTests_PassInByRefLPStr(This,lpstr)	\
    ( (This)->lpVtbl -> PassInByRefLPStr(This,lpstr) ) 

#define IStringTests_PassInByRefLPWStr(This,lpwstr)	\
    ( (This)->lpVtbl -> PassInByRefLPWStr(This,lpwstr) ) 

#define IStringTests_PassInByRefLPUTF8Str(This,lputf8str)	\
    ( (This)->lpVtbl -> PassInByRefLPUTF8Str(This,lputf8str) ) 

#define IStringTests_ReverseBstr(This,bStr,returnValue)	\
    ( (This)->lpVtbl -> ReverseBstr(This,bStr,returnValue) ) 

#define IStringTests_ReverseLPStr(This,lpstr,returnvalue)	\
    ( (This)->lpVtbl -> ReverseLPStr(This,lpstr,returnvalue) ) 

#define IStringTests_ReverseLPWStr(This,lpwstr,returnvalue)	\
    ( (This)->lpVtbl -> ReverseLPWStr(This,lpwstr,returnvalue) ) 

#define IStringTests_ReverseLPUTF8Str(This,lpstr,returnvalue)	\
    ( (This)->lpVtbl -> ReverseLPUTF8Str(This,lpstr,returnvalue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStringTests_INTERFACE_DEFINED__ */



#ifndef __MathEngineLib_LIBRARY_DEFINED__
#define __MathEngineLib_LIBRARY_DEFINED__

/* library MathEngineLib */
/* [uuid] */ 


EXTERN_C const IID LIBID_MathEngineLib;

EXTERN_C const CLSID CLSID_StringTests;

#ifdef __cplusplus

class DECLSPEC_UUID("AC65770F-2F38-4F3A-ABD4-697E53EB8482")
StringTests;
#endif
#endif /* __MathEngineLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


