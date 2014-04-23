
#ifndef WINTER_ILOGADAPTER_H
#define WINTER_ILOGADAPTER_H

#include <string>
using namespace std;

namespace Winter{



class ILogAdapter {
public:
	virtual void debug(const string&) = 0;
	virtual void info(const string&) = 0;
	virtual void warn(const string&) = 0;
	virtual void error(const string&) = 0;
	virtual void fatal(const string&) = 0;
	virtual void log(int, const string&) = 0;
	
	/** 
	 * Destructor
	 */
	virtual ~ILogAdapter(){}
};

} // End namespace Winter
#endif
