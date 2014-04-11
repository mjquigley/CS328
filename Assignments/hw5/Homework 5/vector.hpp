///////////////////////////////////////////////////////////////////
/// @file vector.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief implimentation of an Vector class
///////////////////////////////////////////////////////////////////

template <class T>
Vector<T>& Vector<T>::operator*=(const T& rhs){
	for (int i = 0; i < this->numElements(); ++i){
		this->operator[](i) *= rhs;
	}
	return *this;
}

template <class T>
Vector<T>& Vector<T>::operator*=(const Vector<T>& rhs){
	if (rhs.size != this->numElements()){
		throw SizeMismatchException();
	}
	for (int i = 0; i < this->numElements(); ++i){
		this->ptr_to_data[i] *= rhs[i];
	}
	return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& rhs){
	if (rhs.numElements() != this->numElements()){
		throw SizeMismatchException();
	}
	for (int i = 0; i < this->numElements(); ++i){
		this->operator[](i) += rhs[i];
		if (this->operator[](i) < ZERO_TOLERANCE
			&& this->operator[](i) > -ZERO_TOLERANCE)
		{
			this->operator[](i) = 0;
		}
	}
	return *this;
}

template <class T>
const T Vector<T>::dotProduct(const Vector<T>& other){
	T result = T();
	for (int i = 0; i < other.size; ++i){
		result += this->ptr_to_data[i] * other[i];
	}
	return result;
}



