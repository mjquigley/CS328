///////////////////////////////////////////////////////////////////
/// @file chebyshev.h
/// @author Matthew Quigley CS328 Section A
/// @brief declaration of the chebyshev class
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class Chebyshev
/// @brief calculates the coefficients of a chebyshev polynomial
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn double operator()(int n)
/// @brief calculates the coefficients of a chebyshev polynomial
/// @pre n >= 0
/// @post returns an Array of coefficients of length n+1
/// @return the first n+1 coefficients of a chebyshev polynomial
///////////////////////////////////////////////////////////////////

#ifndef chebyshev_h
#define chebyshev_h
#include <cmath>
#include "array.h"

using namespace std;
const double PI = atan(1.0)*4;

class Chebyshev{
public:
	const Array <double> operator()(int n){
		Array<double> values(n+1);
		for (int k = 0; k <= n; ++k){
			values[k] = cos(((2*n) + 1 - (2*k)) * (PI/((2*n)+2)));
		}
		return values;
	}
};

#endif