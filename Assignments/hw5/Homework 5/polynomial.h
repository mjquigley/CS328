///////////////////////////////////////////////////////////////////
/// @file polynomial.h
/// @author Matthew Quigley CS328 Section A
/// @brief declaration of the polynomial class
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class Polynomisl
/// @brief represents a polynomial
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Polynomial(const Array<T>& coefficients)
/// @brief constructor for polynomial
/// @pre coefficients is an array containg the coefficients of a polynomial
///		 in the format {c1, c2, ... cn} where the polynomial is
///		 f(x) = c1x + c2x^2 + ... + cnx^n
/// @post returns value of polynomial at x
/// @return value of polynomial at x
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Polynomial(const Polynomial& other)
/// @brief copy constructor for polynomial
/// @post creates a new polynomial that is a copy of other
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Polynomial& operator=(const Polynomial& other);
/// @brief copy assignment operator for polynomial
/// @post copys other into the calling polynomial
/// @return the calling object
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn double operator()(T x)
/// @brief calculates value of polynomial at x
/// @pre  +, *=, and * operators are defined for type T
/// @post returns value of polynomial at x
/// @return value of polynomial at x
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn T power(T value, int exponent);
/// @brief calculates the value of value to the exponent power
/// @pre  *= is defined for type T
/// @post returns value of value raised to the exponent power
/// @return value of value raised to the exponent power
///////////////////////////////////////////////////////////////////

#ifndef polynomial_h
#define polynomial_h
#include "array.h"

template <class T>
class Polynomial{
public:
	Polynomial(const Array<T>& coefficients): coefficients(coefficients){}
	Polynomial(const Polynomial& other);
	Polynomial& operator=(const Polynomial& other);
	T operator()(T x);
	
	friend std::ostream& operator<<(std::ostream& out, Polynomial& rhs){
		for (Iterator<T> iter = rhs.coefficients.begin();
			 iter != rhs.coefficients.end(); ++iter){
			out << *iter << std::endl;
		}
		return out;
	}
private:
	Array<T> coefficients;
	T power(T value, int exponent);
};
#include "polynomial.hpp"
#endif
