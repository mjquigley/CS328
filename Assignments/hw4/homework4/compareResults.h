///////////////////////////////////////////////////////////////////
/// @file compareResults.h
/// @author Matthew Quigley CS328 Section A
/// @brief definition of the result comparison class
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class CompareResults
/// @brief This class compares the error of two data sets
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn void operator()(Array<T> newEstimates, Array<T> oldEstimates,
///						Array<T> actualValues)
/// @brief outputs the absolute and relative error and the comparison
///		   of the relative errors
/// @pre  all three parameters have the same length
/// @post outputs the Absolute and relative errors of the points in
///		  newEstimates using actualValues then computes and outputs
///		  the difference in the relative error between newEstimates
///		  and oldEstimates
///////////////////////////////////////////////////////////////////

#ifndef compareResults_h
#define compareResults_h
#include "array.h"
#include <iostream>

template <class T>
class CompareResults{
public:
	void operator()(const Array<T>& newEstimates, const Array<T>& oldEstimates,
			   const Array<T>& actualValues);
};
#include "compareResults.hpp"

#endif
