#ifndef polarCoord_h
#define polarCoord_h

///////////////////////////////////////////////////////////////////
/// @file polarCoord.h
/// @author Matthew Quigley CS328 Section A
/// @brief defines the Polar Coordinate class PolarCoord
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class PolarCoord
/// @brief This class stores a representation of a polar coordinate
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const PolarCoord<T>& operator-() const
/// @brief negation operator
/// @return the negation of the calling PolarCoord
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const T& operator~() const
/// @brief magnitude operator
/// @return the magnitude of the calling PolarCoord
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord<T>& operator!() const
/// @brief conjugate operator
/// @return the conjugate of the calling PolarCoord
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const T& operator[](const bool index) const
/// @brief conjugate operator
/// @param index false to get modulus, true to get argument
/// @return
///			the modulus of the calling PolarCoord if the index is false(0)
///			the argument of the calling PolarCoord if the index is true(1)
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn bool operator<(const PolarCoord<T>& other) const
/// @brief less than operator
/// @param other the PolarCoord to compare the calling object to
/// @return true if the calling object is less than other
///			false otherwise
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn bool operator>(const PolarCoord<T>& other) const
/// @brief greater than operator
/// @param other the PolarCoord to compare the calling object to
/// @return true if the calling object is greater than other
///			false otherwise
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn bool operator==(const PolarCoord<T>& other) const
/// @brief equality operator
/// @param other the PolarCoord to compare the calling object to
/// @return true if the calling object is equal to other
///			false otherwise
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn bool operator!=(const PolarCoord<T>& other) const
/// @brief not equal operator
/// @param other the PolarCoord to compare the calling object to
/// @return true if the calling object is not equal to other
///			false otherwise
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord<T>& operator*(const PolarCoord<T>& other) const
/// @brief multiplication operator
/// @param other the PolarCoord to multiply with the calling object
/// @return a new PolarCoord representing the result of multiplication
///			between the calling object and other
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord<T>& operator/(const PolarCoord<T>& other) const
/// @brief division operator
/// @param other the PolarCoord to divide the calling object by
/// @return a new PolarCoord representing the result of division
///			of the calling object by other
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord<T>& operator=(const PolarCoord<T>& other)
/// @brief assignment operator
/// @param other the PolarCoord to assign to the calling object
/// @post the calling object is equal to other
/// @return the calling object
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn std::ostream& operator<<(const PolarCoord<T>& value) const
/// @brief output streaming operator
/// @param value the PolarCoord to output to the stream
/// @post the PolarCoord value is output to the stream in the format:
///			"modulus argument"
/// @return the calling stream
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn std::istream& operator>>(PolarCoord<T>& value)
/// @brief output streaming operator
/// @param value the PolarCoord to put data read from the stream into
/// @post the PolarCoord value is set to the value read from the stream
///			in the format: "modulus argument"
/// @return the calling stream
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
template <class T>
class PolarCoord{
public:
	PolarCoord<T>(){}
	PolarCoord<T>(const T mod, const T arg): modulus(mod), argument(arg) {}
	PolarCoord<T>(const PolarCoord<T>& other){
		modulus = other.modulus;
		argument = other.argument;
	}
	~PolarCoord<T>(){}
	
	T operator~() const;
	PolarCoord<T>& operator-() const;
	PolarCoord<T>& operator!() const;
	
	T& operator[](const bool index) const;
	
	bool operator<(const PolarCoord<T>& other) const;
	bool operator>(const PolarCoord<T>& other) const;
	bool operator==(const PolarCoord<T>& other) const;
	bool operator!=(const PolarCoord<T>& other) const;
	
	PolarCoord<T>& operator*(const PolarCoord<T>& other) const;
	PolarCoord<T>& operator/(const PolarCoord<T>& other) const;
	PolarCoord<T>& operator=(const PolarCoord<T>& other);
	
	friend std::ostream& operator<<(std::ostream& os,
									const PolarCoord<T>& value){
		return os << value.modulus << ' ' << value.argument;
	}
	friend std::istream& operator>>(std::istream& is, PolarCoord<T>& value){
		is >> value.modulus;
		is >> value.argument;
		return is;
	}
	
	
	const T getModulus() const{
		return this->modulus;
	}
	void setModulus(const T& modulus){
		this->modulus = modulus;
	}
	const T getArgument() const{
		return this->argument;
	}
	void setArgument(const T& argument){
		this->argument = argument;
	}
	
private:
	T modulus;		//the modulus (r) of a polar coordinate
	T argument;		//the argumnet (theta) of a polar coordinate
};
#include "polarCoord.cpp"
#endif
