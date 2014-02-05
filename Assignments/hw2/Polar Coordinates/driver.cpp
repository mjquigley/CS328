///////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Matthew Quigley CS328 Section A
/// @date February 4, 2014
/// @assignment 2
/// @brief driver for assignment 2 (Polar Coordinates)
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "norm.h"
int main(int argc, const char * argv[])
{
	if (argc == 2){
		int numCoordinates;
		std::vector<PolarCoord<double> > allCoordinates;
		std::ifstream inputFile;
		
		inputFile.open(argv[1]);
		inputFile >> numCoordinates;
		allCoordinates = std::vector<PolarCoord<double> > (numCoordinates);
		for (int i = 0; i < numCoordinates; ++i){
			PolarCoord<double> coord;
			inputFile >> coord;
			allCoordinates.push_back(coord);
		}
		Norm<double> norm;
		int result = norm(allCoordinates);
		std::cout << result << std::endl;
	} else {
		std::cout << "Invalid number of arguments: expecting: driver filename"
		<< std::endl;
	}
	
    return 0;
}

