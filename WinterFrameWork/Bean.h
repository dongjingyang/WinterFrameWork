#pragma once
#include "basic.h"
namespace Winter
{
	class CBean
	{
	public:


		class CCBean
		{
		public:
			virtual HRESULT GetBean(LPCTSTR lpcsObjId, void ** pOuter) = 0;
		};
		CBean(CCBean * pCCbean);
		virtual ~CBean();
	public:
		HRESULT GetBean(LPCTSTR lpcsObjId, void ** pOuter);
	private:
		CCBean  * _p;
	};

}
