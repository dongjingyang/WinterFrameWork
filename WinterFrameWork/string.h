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

	//ȥ���ַ����ո�
	static void ver(LPTSTR str)
	{
		int i, n = _tcslen(str);

		TCHAR *p = str;
		for (i = 0; i < n;)
		{
			if (*p != _T(' '))
				str[i++] = *p;
			p++;
		}
		str[i] = _T('');
	}
}

#endif // string_h__
