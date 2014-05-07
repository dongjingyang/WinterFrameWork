
#ifndef WINTER_BASIC_H
#define WINTER_BASIC_H

#include <xstring>
#include <vector>
#include <tchar.h>
#include <winerror.h>
#include <basetyps.h>
#include <memory>
#include <wtypes.h>
using namespace  std;

namespace Winter
{

#define  DCOM   dcom
#define  STR_TYPE_DCOM  _T("dcom")	
#define  MAX_GUID   48
#define DXMLPARSEFAILD(x,explain) { if(!x){THREOWEXCETION(XMLParsing,explain) return false;}}


#define  FAILEDRETURN(hr)  if (FAILED(hr)){return hr;}
#define  RETURN_TRUE(exper,hr)  if (exper){return hr;}
#define _THREOWEXCETION(type,cname,mname,msg)  throw    _##type##Ex(cname,mname,##msg);
#define THREOWEXCETION(type,explain) {_THREOWEXCETION(type,__FILE__,__FUNCTION__,explain)}

#define HRTHREOWEX(x,type,explain,hr)if(!x){_THREOWEXCETION(type,__FILE__,__FUNCTION__,explain);return hr;}
#define  FAILEDNORETURN(x) if (!x){THREOWEXCETION(NonValue,"INVALID arg") return;}
#define	  INVALIDARGRETURN(x) if (!x){THREOWEXCETION(NonValue,"INVALID arg") return E_INVALIDARG;}
#define   NULLRETURN(x) if (!x){THREOWEXCETION(NonValue,"the value is Null") return E_FAIL;}
	/** Value strings */
	typedef std::basic_string<TCHAR>  DS_String;
	typedef std::vector<DS_String> StrValueList;
	typedef std::vector<DS_String>::iterator StrIterator;

	/** A type represents pointer */
	typedef long TPointer;

}

#endif 
