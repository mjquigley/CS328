#ifndef array_h
#define array_h

template <class T>
class Iterator;

template <class T>
class Array{
public:
	friend class Iterator<T>;
	Array(): size(0), ptr_to_data(new T[0]){}
	Array(int size): size(size){
		ptr_to_data = new T[size];
	}
	Array(const Array<T>& other);
	~Array();
	T& operator[](int index);
	const T& operator[](int index) const;
	int numElements() const;
	Array& operator= (const Array& rhs);
	Array& operator= (const T& rhs);
	void setSize(int newSize);

	Iterator<T> begin();
	Iterator<T> end();

private:
	int size;
	T* ptr_to_data;
};


template <class T>
class Iterator{
public:
	Iterator(){}
	Iterator(Array<T>& array): current(array.ptr_to_data), end(array.ptr_to_data + array.size){}
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

#include "array.hpp"
#endif
