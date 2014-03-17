///////////////////////////////////////////////////////////////////
/// @file array.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief driver for assignment 3 - Newton Divided Difference Table
///////////////////////////////////////////////////////////////////

#include "array.h"
#include "newtonDividedDifference.h"
#include "newtonPolynomial.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
int main(int argc, const char * argv[])
{
	if (argc == 2){
		int numPairs;
		Array<std::pair<double, double> > allPairs;
		std::ifstream inputFile;
		
		inputFile.open(argv[1]);
		if (!inputFile){
			std::cout<<"Error opening file"<<std::endl;
			return -1;
		}
		//Load data from input file
		inputFile >> numPairs;
		allPairs = Array<std::pair<double, double> > (numPairs);
		std::cout << "Data Points: " << std::endl;
		for (int i = 0; i < numPairs; ++i){
			double first, second;
			inputFile >> first;
			inputFile >> second;
			std::cout << first << " " << second << std::endl;
			std::pair<double, double> pair =
									std::pair<double, double>(first, second);
			allPairs[i] = pair;
		}
		//Generate the Newton divided difference table
		NewtonDividedDifference<double> divDiff;
		Array<Array<double> > divDifferenceTable = divDiff(numPairs, allPairs);
		
		NewtonPolynomial<double> polynomial(numPairs-1, divDifferenceTable);
	
		std::cout << "Coefficients: " << std::endl;
		polynomial.printCoefficients(std::cout);
		
		//Calculate the interpolated values at each x value
		Array<double> interpolatedValues(11);
		std::cout << "Interpolated Values: " << std::endl;
		int i = 0;
		for (double d = 0.0; d <= 1.0; d+=0.1, ++i){
			interpolatedValues[i] = polynomial(d);
			std::cout << "f(" << d <<") = "
										<< interpolatedValues[i] << std::endl;
		}

		//Calculate the real function value at each x value
		Array<double> actualValues(11);
		std::cout << "Actual Values: " << std::endl;
		i = 0;
		for (double d = 0.0; d <= 1.0; d+=0.1, ++i){
			actualValues[i] = 1/(1+(12*d*d));
			std::cout << "f(" << d <<") = " << actualValues[i] << std::endl;
		}

		Array<double> absoluteError(11);
		std::cout << "Absolute Error: " << std::endl;
		i = 0;
		for (double d = 0.0; d <= 1.0; d+=0.1, ++i){
			absoluteError[i]= std::abs(interpolatedValues[i] - actualValues[i]);
			std::cout << "Error (" << d << "):  "
											<< absoluteError[i] << std::endl;
		}
		
		std::cout << "Relative Error: " << std::endl;
		i = 0;
		for (double d = 0.0; d <= 1.0; d+=0.1, ++i){
			if (actualValues[i] == 0){
				throw DivideByZeroException();
			}
			std::cout << "Error (" << d << "):  "
							<< absoluteError[i] / actualValues[i] << std::endl;
		}
		
		
	} else {
		std::cout << "Invalid number of arguments: expecting: driver filename"
		<< std::endl;
	}
	
    return 0;
}
