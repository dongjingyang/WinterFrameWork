#pragma once
#include "basic.h"
namespace Winter
{
	class CBean
	{
	public:
		CBean();
		virtual ~CBean();
		class CCBean
		{
		public:
			virtual HRESULT GetObject(DS_String lpcsObjId, void ** pOuter);
		protected:
		private:
		};
	public:
		HRESULT GetObject(DS_String lpcsObjId, void ** pOuter);
	private:
		CCBean  * _p;
	};

}
