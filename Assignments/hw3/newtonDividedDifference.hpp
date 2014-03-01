template <class T>
const Array<Array<T> > NewtonDividedDifference<T>::operator()(int numValues, 
								const Array<std::pair<T, T> >& functionValues)
{
	Array<Array<T> > divDiffTable(numValues+1);
	for (int i = 0; i < numValues+1; ++i){
		int size = numValues + 1 - i;
		divDiffTable[i] = Array<T>(size);
		divDiffTable[i][0] = functionValues[i].first;
		divDiffTable[i][1] = functionValues[i].second;
	}

	for (int i = 1; i < numValues; ++i){
		for (int j = 0; j < numValues - i - 1; ++j){
			int numerator = divDiffTable[i][j+1];
			int denominator = divDiffTable[i-1][0];
			if (denominator == 0){
				throw DivideByZeroException();
			}
			divDiffTable[i-1][j+2] = numerator / denominator;
		}
	}
	return divDiffTable;
}
