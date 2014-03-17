///////////////////////////////////////////////////////////////////
/// @file array.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief implimentation of an Array class and its Iterator
///////////////////////////////////////////////////////////////////

template <class T>
Array<T>::Array(const Array<T>& other){
	copyArray(other);
}

template <class T>
Array<T>::~Array(){
	delete[] ptr_to_data;
}

template <class T>
T& Array<T>::operator[](const int index){
	if (index >= size || index < 0){
		throw IndexOutOfRangeException();
	}
	return ptr_to_data[index];
}

template <class T>
const T& Array<T>::operator[](const int index) const{
	if (index >= size || index < 0){
		throw IndexOutOfRangeException();
	}
	return ptr_to_data[index];
}

template <class T>
int Array<T>::numElements() const{
	return size;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs){
	copyArray(rhs);
	return *this;
}

template <class T>
Array<T>& Array<T>::operator=(const T& rhs){
	for (int i = 0; i < size; i++){
		ptr_to_data[i] = rhs;
	}
}

template <class T>
void Array<T>::setSize(int newSize){
	if (newSize < 0){
		throw InvalidSizeException();
	}
	T* temp_ptr_to_data = new T[size];
	int oldSize = size;
	size = newSize;
	int sizeLimit = (oldSize < newSize ? oldSize : newSize);
	temp_ptr_to_data = new T[size];
	for (int i=0; i< sizeLimit; ++i){
		temp_ptr_to_data[i] = ptr_to_data[i];
	}
	delete[] ptr_to_data;
	ptr_to_data = temp_ptr_to_data;
}

template <class T>
Iterator<T> Array<T>::begin(){
	return Iterator<T>(*this);
}

template <class T>
Iterator<T> Array<T>::end(){
	return Iterator<T>(*this, true);
}

template <class T>
void Array<T>::copyArray(const Array<T> &other){
	size = other.size;
	ptr_to_data = new T[size];
	for (int i = 0; i < size; i++){
		ptr_to_data[i] = T(other.ptr_to_data[i]);
	}
}


template <class T>
Iterator<T>::Iterator(Array<T>& array, bool isEnd){
	if (isEnd){
		current = array.ptr_to_data + array.size;
	} else {
		current = array.ptr_to_data;
	}
	end = array.ptr_to_data + array.size;
}

template <class T>
bool Iterator<T>::more(){
	return current < end;
}

template <class T>
void Iterator<T>::operator++(){
	current++;
}

template <class T>
T& Iterator<T>::operator*() const{
	return *current;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& rhs) const{
	return current == rhs.current;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs) const{
	return current != rhs.current;
}

template <class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& rhs){
	current = rhs.current;
	end = rhs.end;
	return *this;
}
