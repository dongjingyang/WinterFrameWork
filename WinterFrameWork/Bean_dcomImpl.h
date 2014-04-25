#pragma once

#include "Bean.h"
#include "LibraryTemplate.h"

namespace Winter
{
	class CBean_dcomImpl :
		public CBean::CCBean
	{
	public:
		CBean_dcomImpl(TBean * pBeanMateri);
		virtual ~CBean_dcomImpl();

		virtual HRESULT GetObject(LPCTSTR lpcsObjId, void ** pOuter);
	private:
		TBean * m_pBeanMateri;
	};
}

