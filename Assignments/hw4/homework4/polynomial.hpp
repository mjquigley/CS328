///////////////////////////////////////////////////////////////////
/// @file polynomial.h
/// @author Matthew Quigley CS328 Section A
/// @brief implimentation of the polynomial class
///////////////////////////////////////////////////////////////////

template <class T>
Polynomial<T>::Polynomial(const Polynomial& other){
	coefficients = Array<T>(other.coefficients);
}

template <class T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial<T>& other){
	coefficients = Array<T>(other.coefficients);
}

template <class T>
T Polynomial<T>::operator()(T x){
	T value = T();
	for (int i = 0; i < coefficients.numElements(); ++i){
		value += coefficients[i] * power(x, i);
	}
	return value;
}

template <class T>
T Polynomial<T>::power(T value, int exponent){
	if (exponent == 0){
		return 1;
	}
	T result = value;
	for (int i = 1; i < exponent; ++i){
		result *= value;
	}
	return result;
}