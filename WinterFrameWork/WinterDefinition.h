#ifndef WINTER_AUTUMNDEFINITION_H
#define WINTER_AUTUMNDEFINITION_H

#include <vector>
#include "Basic.h"

using namespace std;

namespace Winter{


	#define DASSERT(x, _h_r_) { if(!(x)) return _h_r_; }
	#define DASSERTV(x) { if(!(x)) return; }


} // End namespace Winter

#endif
