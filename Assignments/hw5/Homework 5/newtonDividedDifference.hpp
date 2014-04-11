///////////////////////////////////////////////////////////////////
/// @file newtonDividedDifference.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief implimentation of NewtonDividedDifference Table generation class
///////////////////////////////////////////////////////////////////

template <class T>
const Polynomial<T> NewtonDividedDifference<T>::operator()(int numValues,
								const Array<std::pair<T, T> >& functionValues)
{
	Array<Array<T> > divDiffTable(numValues);
	for (int i = 0; i < numValues; ++i){
		int size = numValues + 1 - i;
		divDiffTable[i] = Array<T>(size);
		divDiffTable[i][0] = functionValues[i].first;
		divDiffTable[i][1] = functionValues[i].second;
	}

	for (int j = 2; j <= numValues+1; ++j){
		for (int i = 0; i < numValues+1-j; ++i){
			T numerator = divDiffTable[i+1][j-1] - divDiffTable[i][j-1];
			T denominator = divDiffTable[j+i-1][0] - divDiffTable[i][0];
			if (denominator == 0){
				throw DivideByZeroException();
			}
			divDiffTable[i][j] = numerator / denominator;
		}
	}
	Array<T> coefficients(numValues - 1);
	for (int i = 0; i < numValues - 1; ++i){
		coefficients[i] = divDiffTable[0][i+1];
	}
	return Polynomial<T>(coefficients);
}
