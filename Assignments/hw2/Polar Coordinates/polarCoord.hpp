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
/// @fn PolarCoord()
/// @brief default constructor for PolarCoord
/// @pre type T is numeric type
/// @post a PolarCoord with modulus 0, argument 0 is returned
/// @return a default PolarCoord
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord(const T mod, const T arg)
/// @brief constructor for PolarCoord
/// @pre type T is numeric type
/// @post a PolarCoord with modulus mod, argument arg is returned
/// @return a new Polar coord with modulus mod and argument arg
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord(const PolarCoord<T>& other)
/// @brief copy constructor for PolarCoord
/// @pre type T is numeric type and other is a valid PolarCoord
/// @post a PolarCoord is returned with the modulus and argument values from
///		  other as its modulus and argument values
/// @return a PolarCoord that is a copy of other
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn ~PolarCoord()
/// @brief destructor for PolarCoord
/// @pre PolarCoord has not already been destroyed
/// @post PolarCoord is destroyed
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const T& operator~() const
/// @brief magnitude operator
/// @pre type T has a defined version of std::abs
/// @post the magnitude of the PolarCoord is calculated and returned
/// @return the magnitude of the calling PolarCoord
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const PolarCoord<T>& operator-() const
/// @brief negation operator
/// @pre the unary '-' operator is defined for type T
/// @post a copy of the PolarCoord is created the modulus is negated
///		  and the new PolarCoord is returned
/// @return the negation of the calling PolarCoord
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord<T>& operator!() const
/// @brief conjugate operator
/// @pre '-' operator is defined for type T
/// @post a copy of the PolarCoord is created the argument is negated
///		  and the new PolarCoord is returned
/// @return the conjugate of the calling PolarCoord
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const T& operator[](const bool index) const
/// @brief conjugate operator
/// @param index false to get modulus, true to get argument
/// @pre none
/// @post see @return
/// @return
///			the modulus of the calling PolarCoord if the index is false(0)
///			the argument of the calling PolarCoord if the index is true(1)
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn bool operator<(const PolarCoord<T>& other) const
/// @brief less than operator
/// @param other the PolarCoord to compare the calling object to
/// @pre the precondtion for PolarCoord::operator~ is met
///		 and the '<' operator is defined for type T
/// @post the magnitude of each this polar coordinate is compared to
///		  the magnitude of the PolarCoordinate sent as a parameter
///		  if the magnitude of the calling object is smaller than the
///		  the maginitude of the parameter, return true otherwise return false
/// @return true if the calling object is less than other
///			false otherwise
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn bool operator>(const PolarCoord<T>& other) const
/// @brief greater than operator
/// @param other the PolarCoord to compare the calling object to
/// @pre the precondtion for PolarCoord::operator~ is met
///		 and the '>' operator is defined for type T
/// @post the magnitude of each this polar coordinate is compared to
///		  the magnitude of the PolarCoordinate sent as a parameter
///		  if the magnitude of the calling object is greater than the
///		  the maginitude of the parameter, return true otherwise return false
/// @return true if the calling object is greater than other
///			false otherwise
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn bool operator==(const PolarCoord<T>& other) const
/// @brief equality operator
/// @param other the PolarCoord to compare the calling object to
/// @pre the '==' operator is define for type T
/// @post the modulus and argument of the two PolarCoords are compared return
///		  the result of modulus == other.modulus and argument == other.argument
/// @return true if the calling object is equal to other
///			false otherwise
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn bool operator!=(const PolarCoord<T>& other) const
/// @brief not equal operator
/// @param other the PolarCoord to compare the calling object to
/// @pre the '!=' operator is define for type T
/// @post the modulus and argument of the two PolarCoords are compared return
///		  the result of modulus != other.modulus or argument != other.argument
/// @return true if the calling object is not equal to other
///			false otherwise
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord<T>& operator*(const PolarCoord<T>& other) const
/// @brief multiplication operator
/// @param other the PolarCoord to multiply with the calling object
/// @pre the binary '*' operator and the binary '+' operator is defined for
///		 type T
/// @post a new polarCoord with modulus * other.modulus as its modulus
///		  value and argument + other.argument as its argument value is returned
/// @return a new PolarCoord representing the result of multiplication
///			between the calling object and other
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord<T>& operator/(const PolarCoord<T>& other) const
/// @brief division operator
/// @param other the PolarCoord to divide the calling object by
/// @pre the binary '/' operator and the binary '-' operator is defined for
///		 type T
/// @post a new polarCoord with modulus / other.modulus as its modulus
///		  value and argument - other.argument as its argument value is returned
/// @return a new PolarCoord representing the result of division
///			of the calling object by other
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn PolarCoord<T>& operator=(const PolarCoord<T>& other)
/// @brief assignment operator
/// @param other the PolarCoord to assign to the calling object
/// @pre the '=' operator is defined for type T
/// @post the calling object has its modulus set to other.modulus and its
///		  argument set to other.argument
/// @return the calling object
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn friend std::ostream& operator<<(const PolarCoord<T>& value) const
/// @brief output streaming operator
/// @param value the PolarCoord to output to the stream
/// @pre std::ostream has operator '<<' defined for type T
/// @post the PolarCoord value is output to the stream in the format:
///			"modulus argument"
/// @return the calling stream
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn friend std::istream& operator>>(PolarCoord<T>& value)
/// @brief output streaming operator
/// @param value the PolarCoord to put data read from the stream into
/// @pre std::istream has operator '>>' defined for type T
/// @post the PolarCoord value is set to the value read from the stream
///			in the format: "modulus argument"
/// @return the calling stream
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
template <class T>
class PolarCoord{
public:
	PolarCoord(): modulus(0), argument(0) {}
	PolarCoord(const T mod, const T arg): modulus(mod), argument(arg) {}
	PolarCoord(const PolarCoord<T>& other){
		modulus = other.modulus;
		argument = other.argument;
	}
	~PolarCoord(){}
	
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

class DivideByZeroException{
	public:
		DivideByZeroException(){}
};
#include "polarCoord.cpp"
#endif
