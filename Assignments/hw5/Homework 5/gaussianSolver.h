///////////////////////////////////////////////////////////////////
/// @file gaussianSolver.h
/// @author Matthew Quigley CS328 Section A
/// @brief declaration of a gaussianSolver class
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class GaussianSolver
/// @brief This class is used to solve matrices using gaussian elimination
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn GaussianSolver()
/// @brief default constructor for GaussianSolver
/// @return a new GaussianSolver
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector<T> operator()(const Matrix<T>& matrix, const Vector<T>& vector)
/// @brief perform Gaussian elimination by partial pivoting to obtain a solution
///		   to the system matrix * x = vector
/// @pre type T is defined for 0, the /, *=, and -= operators are defined for
///		 type T
/// @post a vector containing the solution is returned
/// @return a vector containing the solution to the system
///////////////////////////////////////////////////////////////////

#ifndef gaussianSolver_h
#define gaussianSolver_h

#include "matrix.h"

template <class T>
class GaussianSolver{
public:
	GaussianSolver(){}
	
	Vector<T> operator()(const Matrix<T>& matrix, const Vector<T>& vector){
		Matrix<T> result(matrix.rows(), matrix.cols() + 1);
		for (int i = 0; i < matrix.rows(); ++i){
			for (int j = 0; j < matrix.cols(); ++j){
				result[i][j] = matrix[i][j];
			}
			result[i][matrix.cols()] = vector[i];
		}
		for (int pass = 0; pass < result.rows(); ++pass){
			//find the row with the largest pivot
			T max = T();
			int max_row = pass;
			for (int i = pass; i < result.rows(); ++i){
				//get absolute value of potential pivot
				T cur_val = result[pass][i];
				if (cur_val < 0){
					cur_val *= -1;
				}
				if (cur_val > max){
					max = cur_val;
					max_row = i;
				}
			}
			//move the max row to the top
			Vector<T>* temp = result.matrix[pass];
			result.matrix[pass] = result.matrix[max_row];
			result.matrix[max_row] = temp;
			
			//divide row by pivot
			if (result[pass][pass] == 0){
				//all entries in column are 0, move to next column
				continue;
			}
			T val = 1/result[pass][pass];
			(*result.matrix[pass]) *= val;
			for (int i = pass + 1; i < result.rows(); ++i){
				(*result.matrix[i]) += ((result[pass] * T(-1)) *= result[i][pass]);
			}
		}
		Vector<T> solution(vector.numElements());
		int i = vector.numElements()-1;
		int s = matrix.cols();
		solution[i] = result[i][s];
		int j = 1;
		for (; i >= 0; --i, j++){
			solution[i] = result[i][s];
			for (int k = matrix.cols()-1; k < matrix.cols() - j; --k){
				solution[i] -= result[i][k] * solution[k];
			}
		}
		return solution;
	}
};

#endif
