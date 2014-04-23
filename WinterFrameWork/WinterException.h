

#ifndef AUTUMN_EXCEPTION_H
#define AUTUMN_EXCEPTION_H

#include <exception>
#include <string>
#include "WinterLog.h"

using namespace std;
/** 
 * The exceptions used in WinterFramework
 * @version 0.1.0
 * @since 2006-11-30
 */

namespace Winter{

/**  
 * WinterFramework's root exception
 */
class WinterException: public exception{

	/** The class where exception happened. */
	string ClassName;

	/** The method where exception happened. */
	string MethodName;

	/** The cause of exception */
	string ErrMessage;

	/** whole message */
	string WholeMessage;

public:
	/** 
	 * Constructor with class name, method name and cause.
	 */
	WinterException(const string& cname, const string& mname,
					const string& msg):
		ClassName(cname),MethodName(mname),ErrMessage(msg){

		this->WholeMessage = cname + "->" + mname + ": " + msg;
		WinterLog::getInstance()->error(this->WholeMessage.c_str());
	}
	
	/** Destructor. Solaris need this */
	virtual ~WinterException() throw() {}

	/** The method derived from system exception class */
	virtual const char* what() const throw(){
		return this->WholeMessage.c_str();
	}
};

/** Exception happened while initializing bean configuration*/
class _InitException: public WinterException{
public:
	_InitException(const string& cname, const string& mname, const string& msg):
	  WinterException(cname, mname, msg){
	  }

};

/** Exception happened while injecting beans */
class _InjectionException: public WinterException{
public:
	_InjectionException(const string& cname, const string& mname, const string& msg) :
	  WinterException(cname, mname, msg){
	  }
};

/** Exception of not having something definition */
class _MissDefinitionEx : public _InitException{
public:
	_MissDefinitionEx(const string& cname, const string& mname,
					const string& msg):
	  _InitException(cname, mname, msg){
	  }
};

/** Exception of having non value */
class _NonValueEx : public _InitException{
public:
	_NonValueEx(const string& cname, const string& mname, const string& msg) :
		_InitException(cname, mname, msg){
	  }
};

/** Exception of having non instance */
class _NonInstanceEx : public _InitException{
public:
	_NonInstanceEx(const string& cname, const string& mname, const string& msg) :
		_InitException(cname, mname, msg){
	  }
};

/** Exception of not found the object operated on */
class _NotFoundEx : public _InitException{
public:
	_NotFoundEx(const string& cname, const string& mname, const string& msg) :
		_InitException(cname, mname, msg){
	  }
};
/** Unity define */
class  _InitExceEx:public _InitException
{
public:
	_InitExceEx(const string& cname, const string& mname, const string& msg) :
	_InitException(cname, mname, msg)
	{
	}

};
/** Reduplicate definition */
class _ReduplicateEx : public _InitException{
public:
	_ReduplicateEx(const string& cname, const string& mname, const string& msg) :
		_InitException(cname, mname, msg){
	  }
};

/** Parsing XML file error */
class _XMLParsingEx : public _InitException{
public:
	_XMLParsingEx(const string& cname, const string& mname, const string& msg) :
		_InitException(cname, mname, msg){
	  }
};

/** Create bean failed */
class _CreateBeanFailedEx : public _InjectionException{
public:
	_CreateBeanFailedEx(const string& cname, const string& mname,
					   const string& msg):
					   _InjectionException(cname, mname, msg){
	  }
};

/** Create bean failed */
class _SetPropertyFailedEx : public _InjectionException{
public:
	_SetPropertyFailedEx(const string& cname, const string& mname,
						const string& msg):
	  _InjectionException(cname, mname, msg){
	  }
};

} // End namespace Winter
#endif

