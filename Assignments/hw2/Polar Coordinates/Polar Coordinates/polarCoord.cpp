///////////////////////////////////////////////////////////////////
/// @file polarCoord.h
/// @author Matthew Quigley CS328 Section A
/// @brief implimentation of the Polar Coordinate class PolarCoord
///////////////////////////////////////////////////////////////////
#ifndef polarCoord_tpp
#define polarCoord_tpp
template<class T>
T PolarCoord<T>::operator~() const{
	return std::abs(modulus);
}

template<class T>
PolarCoord<T>& PolarCoord<T>::operator-() const{
	return PolarCoord<T>(-modulus, argument);
}

template<class T>
PolarCoord<T>& PolarCoord<T>::operator!() const{
	return PolarCoord<T>(modulus, -argument);
}

template<class T>
T& PolarCoord<T>::operator[](const bool index) const{
	return (index ? argument : modulus);
}

template<class T>
bool PolarCoord<T>::operator<(const PolarCoord<T>& other) const{
	return ~this < ~other;
}

template<class T>
bool PolarCoord<T>::operator>(const PolarCoord<T>& other) const{
	return ~this > ~other;
}

template<class T>
bool PolarCoord<T>::operator==(const PolarCoord<T>& other) const{
	return (modulus == other.modulus && argument == other.argument);
}

template<class T>
bool PolarCoord<T>::operator!=(const PolarCoord<T>& other) const{
	return (modulus != other.modulus || argument != other.argument);
}

template<class T>
PolarCoord<T>& PolarCoord<T>::operator*(const PolarCoord<T>& other) const{
	return PolarCoord<T>(modulus * other.modulus, argument + other.modulus);
}

template<class T>
PolarCoord<T>& PolarCoord<T>::operator/(const PolarCoord<T>& other) const{
	return PolarCoord<T>(modulus / other.modulus, argument - other.modulus);
}

template<class T>
PolarCoord<T>& PolarCoord<T>::operator=(const PolarCoord<T>& other){
	modulus = other.modulus;
	argument = other.argument;
	return *this;
}
#endif
