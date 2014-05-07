#pragma once

#include "Bean.h"
#include "LibraryTemplate.h"
#include "..\Dcom\DComUtility.h"
#include "..\Dcom\IDComBase.h"
namespace Winter
{
	class CBean_dcomImpl :
		public CBean::CCBean
	{
	public:
		CBean_dcomImpl(TBean * pBeanMateri);
		virtual ~CBean_dcomImpl();

		virtual HRESULT GetBean(LPCTSTR lpcsObjId, void ** pOuter);
	private:
		TBean * m_pBeanMateri;
		UTIL::com_ptr<IDComBase>  m_Obj;
	};
}

