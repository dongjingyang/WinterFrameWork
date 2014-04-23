// AggregAtion.h : Declaration of the CAggregAtion

#pragma once
#include "resource.h"       // main symbols

#include "TestComLibrary_i.h"


// CAggregAtion

class ATL_NO_VTABLE CAggregAtion :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAggregAtion, &CLSID_AggregAtion>,
	public IDispatchImpl<IAggregAtion, &IID_IAggregAtion, &LIBID_TestComLibraryLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAggregAtion()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AGGREGATION)

DECLARE_ONLY_AGGREGATABLE(CAggregAtion)

BEGIN_COM_MAP(CAggregAtion)
	COM_INTERFACE_ENTRY(IAggregAtion)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

};

OBJECT_ENTRY_AUTO(__uuidof(AggregAtion), CAggregAtion)
