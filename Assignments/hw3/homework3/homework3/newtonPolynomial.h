///////////////////////////////////////////////////////////////////
/// @file newtonPolynomail.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief definition of NewtonDividedDifference Table storage class
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class NewtonPolynomial
/// @brief This class is used to calculate values using a
///		   Netwon Divided Difference Table
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn NewtonPolynomial(int degree,
///			const Array<Array<T> >& divDiffTable): degree(degree)
/// @brief constructor for NewtonPolynomial
/// @pre divDiffTable is a valid Newton Divided Difference table produced by
///			NewtonDividedDifference()
/// @post create a NewtonPolynomial
/// @return a NetwonPolynomial
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn T operator()(T value)
/// @brief evalute polyomial at value and return result
/// @post returns value of polynomial at value
/// @return value of polynomial at value
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn void printCoefficients(std::ostream& out)
/// @brief output the coefficients of the polyomial
/// @post outputs the coefficients of the polynomial to the out stream
///////////////////////////////////////////////////////////////////

#ifndef newtonPolynomial_h
#define newtonPolynomial_h

#include <iostream>
#include "array.h"

template <class T>
class NewtonPolynomial{
public:
	NewtonPolynomial(int degree,
					 const Array<Array<T> >& divDiffTable): degree(degree){
		this->divDiffTable = Array<Array<T> >(divDiffTable);
	}
	T operator()(T value);
	void printCoefficients(std::ostream& out);
private:
	Array<Array<T> > divDiffTable;
	int degree;
};

#include "newtonPolynomial.hpp"
#endif
