#include "cnewstr.h"
#include <iostream>

using namespace std;

int main()
{
	Cnewstr s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	Cnewstr s1("We are good child!");
	Cnewstr s2="wing";

	//s = s1 + s2 + s;
	//cout << s << "         " << s.getStrLength()<< endl;

	//s.format("%c %s %s %f").arg('T').arg(s1).arg(s2).arg(-2000.40);

	s.replaceBy("a", "T___");
 	cout<< s << "         " << s.getStrLength()<< endl;

	getchar();
	return 0;
}
