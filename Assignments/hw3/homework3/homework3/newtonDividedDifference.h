///////////////////////////////////////////////////////////////////
/// @file newtonDividedDifference.h
/// @author Matthew Quigley CS328 Section A
/// @brief definition of NewtonDividedDifference Table generation class
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class NewtonPolynomial
/// @brief This class is generate a Netwon Divided Difference Table
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const Array<Array<T> > operator()(int numValues,
///			  const Array<std::pair<T, T> >& functionValues)
/// @brief generate Newton divided difference table
/// @pre functionValues contains numValues pairs of function values
/// @post returns a Netwon Divided Difference Table
/// @return a Netwon Divided Difference Table
///////////////////////////////////////////////////////////////////

#ifndef newtonDividedDifference_h
#define newtonDividedDifferenceArray_h 
#include "array.h"
#include <utility>
#include <iostream>
#include <vector>

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
