#include "AssemblyPlant.h"
#include "XmlMine.h"
#include "WinterException.h"
#include "RunningObjTable.h"
#include "Bean_dcomImpl.h"

namespace Winter
{
	CAssemblyPlant::CAssemblyPlant(CXmlMine* xmlMine)
	{
		HRESULT hr = AssemblyLibrary(xmlMine);

	}
	CAssemblyPlant::~CAssemblyPlant()
	{

	}

	HRESULT CAssemblyPlant::AssemblyLibrary(CXmlMine* xmlMine)
	{
		INVALIDARGRETURN(xmlMine);
		DS_LIBRARYVEC   *vecTemp = xmlMine->GetVecLibrary();
		NULLRETURN(vecTemp);
		NULLRETURN(vecTemp->size());

		for (DS_LIBRARYVEC::const_iterator iterLib = vecTemp->begin(); iterLib != vecTemp->end(); iterLib++)
		{
			shared_ptr<TLibrary>libTemp = *iterLib;
			NULLRETURN(libTemp);
			if (libTemp->vecBeans.empty())
			{
				continue;
			}
			
			DS_BEANSVEC  *vecBean = &(libTemp->vecBeans);
			for (DS_BEANSVEC::const_iterator iterBean = vecBean->begin(); iterBean != vecBean->end();iterBean ++ )
			{
				shared_ptr<TBean> beanTemp = *iterBean;
				auto spBean = make_shared<CBean>(new CBean_dcomImpl(beanTemp.get()));
				m_Rot.Regesiter(beanTemp->tCLsid.c_str(), spBean.get());
			}
		}
		return S_OK;
	}

}