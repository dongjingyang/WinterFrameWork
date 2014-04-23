#ifndef string_h__
#define string_h__

#include <sstream>
#include <string>  
using namespace std;
namespace Winter
{
	template<typename T>
	std::string toString(const T& value)
	{
		std::ostringstream oss;
		oss << value;
		return oss.str();
	}
}

#endif // string_h__
