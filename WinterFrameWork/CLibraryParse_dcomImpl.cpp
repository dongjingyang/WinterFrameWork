#include "CLibraryParse_dcomImpl.h"
#include "xmlParser.h"
#include <memory>
#include "WinterException.h"
using namespace  std;

namespace Winter
{


	bool CLibraryParse_dcomImpl::ParseLibrary( XMLNode& xml, TLibrary& lib )
	{
		// parsing beans
		int i, pos, n = 0;
		XMLCSTR  beanDelayLoad = xml.getAttribute(_T("delayload"));
		if (!beanDelayLoad)
		{
			beanDelayLoad = _T("false");
		}
		lib.bDelayLoad = boolAttribute(beanDelayLoad);
		XMLCSTR  beanTag = _T("bean");
		XMLNode beans = xml.getChildNode(_T("beans"));

		n = beans.nChildNode(beanTag);
		DXMLPARSEFAILD(n, "beans is null");
		for (pos = 0, i = 0; i < n; i++)
		{
			auto   spBean = make_shared<TBean>();
			XMLNode beanNode = beans.getChildNode(beanTag, &pos);
			parseBean(beanNode, spBean);
			lib.vecBeans.push_back(spBean);
		}
		return true;
	}

	CLibraryParse_dcomImpl::CLibraryParse_dcomImpl()
	{

	}

	CLibraryParse_dcomImpl::~CLibraryParse_dcomImpl()
	{
		return ;
	}

	bool CLibraryParse_dcomImpl::parseBean(XMLNode beanNode, shared_ptr<TBean> spBean)
	{
		XMLCSTR propsTag = _T("properties");
		XMLCSTR argsTag = _T("constructor-arg");
		XMLCSTR dependTag = _T("depends-on");
		XMLCSTR name = beanNode.getAttribute(_T("name"));
		DXMLPARSEFAILD(name, "name is null!!");
		XMLCSTR strClsid = beanNode.getText();
		DXMLPARSEFAILD(strClsid,"strCLsid is null!!");
		spBean->tName = name;
		spBean->tCLsid = strClsid;
		return true;
	}

	bool CLibraryParse_dcomImpl::boolAttribute(const DS_String value)
	{
		if (value.compare(_T("true")) == 0)
			return true;
		else if (value.compare(_T("false")) == 0)
			return false;
		else
		{
			THREOWEXCETION( XMLParsing, "The value of   must be 'true' or 'false'.");
			return true;
		}
	}
}
