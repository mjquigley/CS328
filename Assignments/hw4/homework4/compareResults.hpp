///////////////////////////////////////////////////////////////////
/// @file compareResults.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief implimentation of the result comparison class
///////////////////////////////////////////////////////////////////

template <class T>
void CompareResults<T>::operator()(const Array<T>& newEstimates, const Array<T>& oldEstimates,
								   const Array<T>& actualValues)
{
	Array<double> absoluteError(newEstimates.numElements());
	Array<double> absoluteError2(oldEstimates.numElements());
	std::cout << "Absolute Error: " << std::endl;
	int i = 0;
	for (double d = 0.1; d <= 0.9; d+=0.2, ++i){
		absoluteError[i]= std::abs(newEstimates[i] - actualValues[i]);
		std::cout << "Error (" << d << "):  "
		<< absoluteError[i] << std::endl;
		absoluteError2[i] = std::abs(oldEstimates[i] - actualValues[i]);
	}
	
	Array<double> relativeError(newEstimates.numElements());
	std::cout << "Relative Error: " << std::endl;
	i = 0;
	for (double d = 0.1; d <= 0.9; d+=0.2, ++i){
		if (actualValues[i] == 0){
			throw DivideByZeroException();
		}
		relativeError[i] = absoluteError[i] / actualValues[i];
		std::cout << "Error (" << d << "):  " << relativeError[i]
		<< std::endl;
	}
	
	i = 0;
	for (double d = 0.1; d <= 0.9; d+=0.2, ++i){
		if (actualValues[i] == 0){
			throw DivideByZeroException();
		}
		std::cout << "Assignment 3 relative error is "
		<< (absoluteError2[i] / actualValues[i]) - relativeError[i]
		<< " greater than Chebyshev relative error at f(" << d << ")"
		<< std::endl;
	}
}
