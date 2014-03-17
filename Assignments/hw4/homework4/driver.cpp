///////////////////////////////////////////////////////////////////
/// @file array.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief driver for assignment 3 - Newton Divided Difference Table
///////////////////////////////////////////////////////////////////

#include "array.h"
#include "newtonDividedDifference.h"
#include "chebyshev.h"
#include "function.h"
#include "compareResults.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <stdlib.h>
int main(int argc, const char * argv[])
{
	if (argc == 3){
		Chebyshev chebyshev;
		Array<std::pair<double, double> > allPairs;
		std::ifstream inputFile;
		
		int numChebyshevNodes = atoi(argv[1]);
		

		allPairs = Array<std::pair<double, double> > (numChebyshevNodes);
		std::cout << "Data Points: " << std::endl;
		Array<double> xValues = chebyshev(numChebyshevNodes);
		Function<double> funct;
		for (int i = 0; i < numChebyshevNodes; ++i){
			double yValue = funct(xValues[i]);
			std::cout << xValues[i] << " " << yValue << std::endl;
			std::pair<double, double> pair =
								std::pair<double, double>(xValues[i], yValue);
			allPairs[i] = pair;
		}
		//Generate the Newton divided difference table
		NewtonDividedDifference<double> divDiffChebyshev;
		Polynomial<double> chebyshevPolynomial = divDiffChebyshev(numChebyshevNodes, allPairs);
			
		std::cout << "Coefficients: " << std::endl;
		std::cout << chebyshevPolynomial;
		
		//Calculate the interpolated values at each x value
		Array<double> interpolatedValues(5);
		std::cout << "Interpolated Values: " << std::endl;
		int i = 0;
		for (double d = 0.1; d <= 0.9; d+=0.2, ++i){
			interpolatedValues[i] = chebyshevPolynomial(d);
			std::cout << "f(" << d <<") = "
										<< interpolatedValues[i] << std::endl;
		}
		
		//Calculate the actual values at each x value
		Array<double> actualValues(5);
		std::cout << "Actual Values: " << std::endl;
		i = 0;
		for (double d = 0.1; d <= 0.9; d+=0.2, ++i){
			actualValues[i] = funct(d);
			std::cout << "f(" << d <<") = "
			<< actualValues[i] << std::endl;
		}
		
		int numPairs;
		inputFile.open(argv[2]);
		if (!inputFile){
			std::cout<<"Error opening file"<<std::endl;
			return -1;
		}
		inputFile >> numPairs;
		allPairs = Array<std::pair<double, double> > (numPairs);
		for (int i = 0; i < numPairs; ++i){
			double first, second;
			inputFile >> first;
			inputFile >> second;
			std::pair<double, double> pair =
									std::pair<double, double>(first, second);
			allPairs[i] = pair;
		}
		
		
		//Generate the Newton divided difference table
		NewtonDividedDifference<double> divDiffEvenSpacing;
		Polynomial<double> polynomialEvenSpacing = divDiffEvenSpacing(numPairs, allPairs);
		
		
		std::cout << "Coefficients: For even spaced polynomial" << std::endl;
		std::cout << polynomialEvenSpacing;
				
		
		//Calculate the interpolated values at each x value
		Array<double> interpolatedValuesEvenSpacing(5);
		std::cout << "Interpolated Values with Even Spacing: " << std::endl;
		i = 0;
		for (double d = 0.1; d <= 0.9; d+=0.2, ++i){
			interpolatedValuesEvenSpacing[i] = polynomialEvenSpacing(d);
			std::cout << "f(" << d <<") = "
			<< interpolatedValuesEvenSpacing[i] << std::endl;
		}
		
		CompareResults<double> compare;
		compare(interpolatedValues, interpolatedValuesEvenSpacing, actualValues);


		
		
	} else {
		std::cout << "Invalid number of arguments: expecting: driver numPoints filename"
		<< std::endl;
	}
	
    return 0;
}
