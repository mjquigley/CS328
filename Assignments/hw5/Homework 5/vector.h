///////////////////////////////////////////////////////////////////
/// @file vector.h
/// @author Matthew Quigley CS328 Section A
/// @brief declaration of an Vector class and its Iterator
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class Vector : public Array<T>
/// @brief This class stores an Vector of variable size
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector(int initialSize)
/// @brief constructor for Vector that takes default size
/// @pre type T can be stored in an Vector, initialSize > 0
/// @post an empty Vector with size initialSize is returned
/// @return an empty Vector with size intialSize
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector<T>& operator*=(const T& rhs);
/// @brief scalar multiplication
/// @pre *= must be defined for type T
/// @post the calling vector is changed to be the result of scalar
///		  multiplication
/// @return the calling object
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector<T>& operator*=(const Vector<T>& rhs);
/// @brief compute the cross product of two vectors
/// @pre *= must be defined for type T
/// @post the calling vector is changed to be the cross product of
///	      the calling vector and rhs
/// @return the calling object
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector<T>& operator+=(const Vector<T>& rhs);
/// @brief compute the addition of two vectors
/// @pre += must be defined for type T and the calling object must be
///		 the same size as vector rhs.
/// @post the calling vector is changed to be the result of
///		  addition with the rhs vector.
/// @return the calling object
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const T dotProduct(const Vector<T>& other);
/// @brief compute the dot product of two vectors
/// @pre * and += must be defined for type T and the calling object must be
///		 the same size as vector rhs.
/// @post the calling vector is changed to be the dot product of
///		  the calling object and the rhs vector.
/// @return the calling object
///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////
/// @fn Vector<T> operator*(const Vector<T>& lhs, const T& rhs)
/// @brief scalar multiplication
/// @pre *= must be defined for type T
/// @post a vector is returned that is the result of scalar multiplication
///		  between lhs and rhs
/// @return the resulting product of vector lhs and scalar rhs
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector<T>& operator*(const Vector<T>& lhs, const Vector<T>& rhs);
/// @brief compute the cross product of two vectors
/// @pre *= must be defined for type T
/// @post returns a vector that is the cross product of
///	      the vector lhs and the vector rhs
/// @return the cross product of lhs and rhs
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector<T>& operator+(const Vector<T>& lhs, const Vector<T>& rhs)
/// @brief compute the addition of two vectors
/// @pre += must be defined for type T and rhs must be the same size as lhs
/// @post returns a vector that is the result of lhs + rhs
/// @return the sum of lhs and rhs
///////////////////////////////////////////////////////////////////


#ifndef vector_h
#define vector_h
#include <iostream>
#include "array.h"

#define ZERO_TOLERANCE 0.000001

template <class T>
class Vector : public Array<T>{
public:
	Vector(int size): Array<T>(size){}
	Vector<T>& operator*=(const T& rhs);
	Vector<T>& operator*=(const Vector<T>& rhs);
	Vector<T>& operator+=(const Vector<T>& rhs);
	
	const T dotProduct(const Vector<T>& other);
};

template <typename T>
Vector<T> operator*(const Vector<T>& lhs, const T& rhs){
	Vector<T> result(lhs);
	result *= rhs;
	return result;
}

template <typename T>
Vector<T> operator*(const Vector<T>& lhs, const Vector<T>& rhs){
	Vector<T> result(lhs);
	result *= rhs;
	return result;
}

template <typename T>
Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs){
	Vector<T> result(lhs);
	result += rhs;
	return result;
}

class SizeMismatchException{
	
};

#include "vector.hpp"
#endif
