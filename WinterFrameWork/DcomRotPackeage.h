#pragma once

#include "..\Dcom\DComBase.h"
#include "..\Dcom\DCom.h"
#include "..\Dcom\DComClassImpl.h"
#include "RunningObjTable.h"
using namespace  dscom;

namespace Winter
{
	// {EFA45E96-AB63-493E-8ACE-58C5323C32AD}
	static const GUID CLSID_CRunningObjectTable =
	{ 0xefa45e96, 0xab63, 0x493e, { 0x8a, 0xce, 0x58, 0xc5, 0x32, 0x3c, 0x32, 0xad } };

	class CRunningObjTable;
	class CDcomRotPackeage : public CDSClassImpl<CDcomRotPackeage>, public IDsRunningObjectTable, public CUnknownImp
	{
	public:
		CDcomRotPackeage(CRunningObjTable *pWinterRot);
		~CDcomRotPackeage();
		UNKNOWN_IMP1(IDsRunningObjectTable);

		virtual STDMETHODIMP Register(const GUID& rpid, IDComBase *punk);

		virtual STDMETHODIMP Revoke(const GUID& rpid);

		virtual STDMETHODIMP IsRunning(const GUID& rpid);

		virtual STDMETHODIMP GetObject(const CLSID& clsid,const GUID& rpid, IDComBase **ppunk);

		virtual STDMETHODIMP RevokeAll();

		static CDcomRotPackeage & Instance()
		{
			static CDcomRotPackeage Rot(&CRunningObjTable::Instance());
			return Rot;
		}
	private:
		CRunningObjTable  *m_Rot;
	};
}


