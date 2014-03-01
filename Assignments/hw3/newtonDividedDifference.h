#ifndef newtonDividedDifference_h 
#define newtonDividedDifferenceArray_h 
#include "array.h"
#include <utility>

template<class T>
class NewtonDividedDifference{
public:
	const Array<Array<T> > operator()(int numValues, 
							const Array<std::pair<T, T> >& functionValues);
};

class DivideByZeroException{
public:
	DivideByZeroException(){};
};

#include "newtonDividedDifference.hpp" 
#endif
