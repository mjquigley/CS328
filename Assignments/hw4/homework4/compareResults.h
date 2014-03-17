///////////////////////////////////////////////////////////////////
/// @file compareResults.h
/// @author Matthew Quigley CS328 Section A
/// @brief definition of the result comparison class
///////////////////////////////////////////////////////////////////

#ifndef compareResults_h
#define compareResults_h
#include "array.h"
#include <iostream>

template <class T>
class CompareResults{
public:
	void operator()(Array<T> newEstimates, Array<T> oldEstimates,
			   Array<T> actualValues);
};
#include "compareResults.hpp"

#endif
