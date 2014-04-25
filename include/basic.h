
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

namespace Winter{

#define  DCOM   dcom
#define  STR_TYPE_DCOM  _T("dcom")	

#define DXMLPARSEFAILD(x,explain) { if(!x){THREOWEXCETION(XMLParsing,explain) return false;}}

#define _THREOWEXCETION(type,cname,mname,msg)  throw    _##type##Ex(cname,mname,##msg);
#define THREOWEXCETION(type,explain) {_THREOWEXCETION(type,__FILE__,__FUNCTION__,explain)}

#define HRTHREOWEX(x,type,explain,hr)if(!x){_THREOWEXCETION(type,__FILE__,__FUNCTION__,explain);return hr;}
	/** Value strings */
	typedef std::basic_string<TCHAR>  DS_String;
	typedef std::vector<DS_String> StrValueList;
	typedef std::vector<DS_String>::iterator StrIterator;

	/** A type represents pointer */
	typedef long TPointer;

}

#endif 
