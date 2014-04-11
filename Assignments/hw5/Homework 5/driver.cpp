///////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Matthew Quigley CS328 Section A
/// @brief driver for assignment 5 - Gaussian Elimination
///////////////////////////////////////////////////////////////////

#include "gaussianSolver.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <stdlib.h>

int main(int argc, const char * argv[]){
	if (argc != 2){
		std::cout<<"Invalid arguments: excpeted \"driver filename\""<<std::endl;
		exit(-1);
	}
	int dimension;
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	inputFile >> dimension;
	Matrix<double> matrix(dimension, dimension);
	inputFile >> matrix;
	std::cout << "Input matrix:" << std::endl;
	std::cout << matrix << std::endl;
	Matrix<double> transpose = matrix.transpose();
	std::cout << "Input matrix transpose:" << std::endl;
	std::cout << transpose << std::endl;
	Matrix<double> identity_matrix = matrix * transpose;
	std::cout << "Input matrix x transpose:" << std::endl;
	std::cout << identity_matrix << std::endl;
	GaussianSolver<double> gaussian;
	Vector<double> vector(dimension);
	inputFile >> vector;
	Vector<double> solution = gaussian(matrix, vector);
	std::cout << "Solution:" << std::endl;
	std::cout << solution << std::endl;
	return 0;
}
