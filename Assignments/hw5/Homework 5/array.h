///////////////////////////////////////////////////////////////////
/// @file array.h
/// @author Matthew Quigley CS328 Section A
/// @brief declaration of an Array class and its Iterator
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class Array
/// @brief This class stores an array of variable size
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Array()
/// @brief default constructor for Array
/// @pre type T can be stored in an array
/// @post an empty array with size 0 is returned
/// @return a default Array
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Array(in initialSize)
/// @brief constructor for Array that takes default size
/// @pre type T can be stored in an array, initialSize > 0
/// @post an empty array with size initialSize is returned
/// @return an empty Array with size intialSize
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Array(const Array<T>& other)
/// @brief copy constructor for Array
/// @pre type T can be stored in an array
/// @post an array that is a deep copy of the array other
/// @return a copied Array
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn ~Array()
/// @brief destructor for Array
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn T& operator[](int index)
/// @brief element access operator for Array
/// @pre index >0 & < size of array
/// @post a reference to the element at index is returned
/// @return a reference to the element in the Array at index
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn const T& operator[](int index) const
/// @brief const element access operator for Array
/// @pre index >0 & < size of array
/// @post a const reference to the element at index is returned
/// @return a const reference to the element in the Array at index
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn int numElements() const
/// @brief get the size of the array
/// @return the size of the array
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Array& operator= (const Array<T>& rhs)
/// @brief assignment operator for Arrays
/// @post lhs becomes a copy of rhs
/// @return this
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Array& operator= (const T& rhs)
/// @brief assignment operator for Arrays
/// @post lhs is filled with copies of rhs
/// @return this
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn void setSize(int newSize)
/// @brief change the size of an array
/// @post calling object becomes a new array with size newSize
/// @return the calling object
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Iterator<T> begin()
/// @brief returns an iterator at the beginning of the Array
/// @post an Iterator pointing to the first element of the array is returned
/// @return an iterator pointing to the first element of the array
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Iterator<T> end()
/// @brief returns an iterator at the end of the Array
/// @post an Iterator pointing to the end of the Array is returned
/// @return an iterator pointing to the end of the array
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn friend std::ostream& operator<<(std::ostream& out,const Array<T>& array)
/// @brief outputs the array to out
/// @pre out<< is defined for type T
/// @post outputs the array to out in the format { a, b, c }
/// @return a refernece to the calling stream
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn friend std::istream& operator>>(std::istream& in, Array<T>& array)
/// @brief reads in values into an array
/// @pre in>> is defined for type T
/// @post reads in array.numElements items from the stream and
///		  puts them in array
/// @return a refernece to the calling stream
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class Iterator
/// @brief This class functions as an iterator for the Array class
///////////////////////////////////////////////////////////////////

#ifndef array_h
#define array_h
#include <iostream>

template <class T>
class Iterator;

template <class T>
class Array{
public:
	friend class Iterator<T>;
	Array(): size(0), ptr_to_data(new T[0]){}
	Array(const int initialSize): size(initialSize), ptr_to_data (new T[size]){}
	Array(const Array<T>& other);
	~Array();
	T& operator[](const int index);
	const T& operator[](const int index) const;
	int numElements() const;
	Array<T>& operator= (const Array<T>& rhs);
	Array<T>& operator= (const T& rhs);
	void setSize(int newSize);

	Iterator<T> begin() const;
	Iterator<T> end() const;
	
	friend std::ostream& operator<<(std::ostream& out, const Array<T>& array){
		out << "{ ";
		for (int i = 0; i < array.size; ++i){
			out << array[i];
			if (i+1 != array.size){
				out << ", ";
			}
		}
		out << " }";
		return out;
	}
	
	friend std::istream& operator>>(std::istream& in, Array<T>& array){
		for (int i = 0; i < array.numElements(); ++i){
			in >> array[i];
		}
		return in;
	}
private:
	int size;
	T* ptr_to_data;
	
	void copyArray(const Array<T>& other);
};


template <class T>
class Iterator{
public:
	Iterator(){}
	Iterator(Array<T>& array): current(array.ptr_to_data),
							   end(array.ptr_to_data + array.size){}
	Iterator(Array<T>& array, bool isEnd);
	bool more();
	void operator++();
	T& operator*() const;
	bool operator==(const Iterator<T>& rhs) const;
	bool operator!=(const Iterator<T>& rhs) const;
	Iterator<T>& operator=(const Iterator<T>& rhs);
private:
	T* current;
	T* end;
};

class IndexOutOfRangeException{
public:
	IndexOutOfRangeException(){}
};

class InvalidSizeException{
public:
	InvalidSizeException(){}
};

#include "array.hpp"
#endif
