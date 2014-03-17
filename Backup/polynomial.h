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
/// @fn double operator()(T x)
/// @brief calculates value of polynomial at x
/// @pre  +, *=, and * operators are defined for type T
/// @post returns value of polynomial at x
/// @return value of polynomial at x
///////////////////////////////////////////////////////////////////

#ifndef polynomial_h
#define polynomial_h
#include "array.h"

template <class T>
class Polynomial{
public:
	Polynomial(const Array<T>& coefficients): coefficients(coefficients){
		
	}
	
	Polynomial(const Polynomial& other){
		coefficients = Array<T>(other.coefficients);
	}
	
	Polynomial& operator=(const Polynomial& other){
		coefficients = Array<T>(other.coefficients);
	}
	
	T operator()(T x){
		T value = T();
		for (int i = 0; i < coefficients.numElements(); ++i){
			value += coefficients[i] * power(x, i);
		}
		return value;
	}
	
	Polynomial& operator+=(const Polynomial& rhs){
		int minLength = std::min(coefficients.numElements(), rhs.numElements());
		int lengthLimit = minLength;
		if (coefficients.numElements() < rhs.numElements()){
			coefficients.setSize(rhs.numElements());
			lengthLimit = coefficients.numElements();
		}
		for (int i = 0; i < lengthLimit; ++i){
			coefficients[i] += rhs.coefficients[i];
		}
		return this;
	}
	
	friend Polynomial& operator+(const Polynomial& lhs, const Polynomial& rhs){
		Polynomial p(lhs);
		return p += rhs;
	}
	
	Polynomial& operator-=(const Polynomial& rhs){
		int minLength = std::min(coefficients.numElements(), rhs.numElements());
		int lengthLimit = minLength;
		if (coefficients.numElements() < rhs.numElements()){
			coefficients.setSize(rhs.numElements());
			lengthLimit = coefficients.numElements();
		}
		for (int i = 0; i < lengthLimit; ++i){
			coefficients[i] -= rhs.coefficients[i];
		}
		return this;
	}
	
	friend Polynomial& operator-(const Polynomial& lhs, const Polynomial& rhs){
		Polynomial p(lhs);
		return p += rhs;
	}
	
	Polynomial& operator*=(const T constant){
		for (int i = 0; i < coefficients.numElements(); ++i){
			coefficients[i] *= constant;
		}
	}
	
	friend Polynomial& operator*(const Polynomial& lhs, const T constant){
		Polynomial p(lhs);
		return p *= constant;
	}
	
	friend Polynomial& operator-(const Polynomial& poly){
		return poly * -1;
	}
	
	void multiplyByPowerOfX(int xPow){
		coefficients.setSize(coefficients.numElements + xPow);
		for (int i = coefficients.numElements; i >= xPow; ++i){
			coefficients[i] = coefficients[i-1];
		}
		for (int i = 0; i < xPow; ++i){
			coefficients[i] = 0;
		}
	}
	
	friend std::ostream& operator<<(std::ostream& out, Polynomial& rhs){
		for (Iterator<T> iter = rhs.coefficients.begin();
						 iter != rhs.coefficients.end(); ++iter){
			out << *iter << std::endl;
		}
		return out;
	}
	
private:
	Array<T> coefficients;
	T power(T value, int exponent){
		if (exponent == 0){
			return 1;
		}
		T result = value;
		for (int i = 1; i < exponent; ++i){
			result *= value;
		}
		return result;
	}
	
};

#endif