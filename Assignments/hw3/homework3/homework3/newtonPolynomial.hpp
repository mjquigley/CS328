///////////////////////////////////////////////////////////////////
/// @file newtonPolynomail.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief implimentation of NewtonDividedDifference Table storage class
///////////////////////////////////////////////////////////////////

#include "newtonPolynomial.h"

template <class T>
T NewtonPolynomial<T>::operator()(T value){
	T total = T();
	for (int i = 0; i < degree + 1; ++i){
		T val = divDiffTable[0][i+1];
		for (int j = 0; j < i; ++j){
			val *= (value - divDiffTable[j][0]);
		}
		total += val;
	}
	return total;
}

template <class T>
void NewtonPolynomial<T>::printCoefficients(std::ostream& out){
	for (int i = 0; i < degree + 1; ++i){
		out << divDiffTable[0][i+1] << std::endl;
	}
}
