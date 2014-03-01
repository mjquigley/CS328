#include "array.h"
#include "newtonDividedDifference.h"
#include <iostream>
#include <fstream>
#include <utility>
int main(int argc, const char * argv[])
{
	if (argc == 2){
		int numPairs;
		Array<std::pair<double, double> > allPairs;
		std::ifstream inputFile;
		
		inputFile.open(argv[1]);
		inputFile >> numPairs;
		allPairs = Array<std::pair<double, double> > (numPairs);
		for (int i = 0; i < numPairs; ++i){
			std::pair<double, double> pair = std::pair<double, double>();
			inputFile >> pair.first;
			inputFile >> pair.second;
			allPairs[i] = pair;
		}
		NewtonDividedDifference<double> divDiff;
		Array<Array<double> > divDifferenceTable = divDiff(numPairs, allPairs);
		//std::cout << result << std::endl;
		for (Iterator<Array<double> > it = divDifferenceTable.begin(); it != divDifferenceTable.end(); ++it){
			for (Iterator<double> it2 = (*it).begin(); it2 != (*it).end(); ++it2){
				std::cout<<*it2<<" ";
			}
			std::cout<<std::endl;
		}
	} else {
		std::cout << "Invalid number of arguments: expecting: driver filename"
		<< std::endl;
	}
	
    return 0;
}
