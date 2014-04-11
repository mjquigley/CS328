///////////////////////////////////////////////////////////////////
/// @file matrix.h
/// @author Matthew Quigley CS328 Section A
/// @brief declaration of an Matrix class
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @class Matrix
/// @brief This class represents and stores matrices of varrying dimensions
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Matrix(int rows, int columns)
/// @brief constructor for a matrix that takes its dimensions
/// @pre rows & columns are > 0
/// @post an empty matrix with given number of rows and columns is returned
/// @return a new matrix with the given dimensions
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Matrix(const Matrix<T>& other)
/// @brief copy constructor for a matrix
/// @pre other is a valid matrix
/// @post a copy of other is returned
/// @return a new matrix that is a copy of other is returned
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn ~Matrix()
/// @brief destructor for Matrix
/// @pre none
/// @post the matrix is deleted
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn int rows() const
/// @brief get number of rows in matrix
/// @pre matrix is valid
/// @return the number of rows in the matrix
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn int cols() const
/// @brief return the number of columns in the matrix
/// @pre rows() must be >0
/// @return the number of columns in the matrix
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector<T>& operator[](int row) const
/// @brief element accessor for the matrix
/// @pre row is within the range {0, (rows()-1)}
/// @post returns a reference to a Vector representing the row number
///		  row of the matrix
/// @return the rowth row of the matrix
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Matrix<T> operator*(const Matrix<T>& rhs)
/// @brief multiply the current matrix by Matrix rhs
/// @pre this->rows() == rhs.cols() and the += and * operators are defined for
///		 type T
/// @post returns a new matrix that is the result of the multiplication of
///		  the calling matrix by rhs
/// @return the result of multiplication of the calling matrix by rhs
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Vector<T> operator*(const Vector<T>& rhs)
/// @brief multiply the current matrix by Vector rhs
/// @pre this->rows() == rhs.numElements() and the += and * operators are
///		 defined for type T
/// @post returns a new matrix that is the result of the multiplication of
///		  the calling matrix by rhs
/// @return the result of multiplication of the calling matrix by rhs
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Matrix<T>& operator*=(const T& rhs)
/// @brief multiply the current matrix by scalar rhs
/// @pre the * operator is defined for type T
/// @post modify the calling matrix to make it the result of the multiplication
///		  of the calling matrix by rhs
/// @return the calling matrix
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Matrix<T>& operator+=(const Matrix<T>& rhs)
/// @brief add Matrix rhs to the calling matrix
/// @pre the calling matrix and rhs have the same dimensions and the
///		 += operator is defined for type T
/// @post modifies the calling matrix so that it contains the sum of the calling
///		  matrix and rhs
/// @return the calling matrix
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Matrix<T> transpose() const
/// @brief get the transpose of the matrix
/// @post returns the transpose of the matrix
/// @return the transpose of the matrix
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn friend std::ostream& operator<<(std::ostream& out,const Matrix<T>& array)
/// @brief outputs the matrix to out
/// @pre out<< is defined for type T
/// @post outputs the matrix in the format {{ a, b, c },\n { d, e, f }}
///		  Note: formated for easy input into Wolfram Mathmatica
/// @return a refernece to the calling stream
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn friend std::istream& operator>>(std::istream& in, Matrix<T>& array)
/// @brief reads in values into a matrix
/// @pre in>> is defined for type T
/// @post reads in matrix.rows() * matrix.cols() items from the stream and
///		  puts them in a matrix
/// @return a refernece to the calling stream
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Matrix<T>& operator*(const Matrix<T>& lhs, const T& rhs)
/// @brief multiply the matrix lhs by scalar rhs
/// @pre the * operator is defined for type T
/// @post returna new matrix that isthe result of the multiplication
///		  of lhs by rhs
/// @return a new matrix that represents lhs * rhs
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
/// @fn Matrix<T>& operator+(const Matrix<T>& lhs, const Matrix<T>& rhs)
/// @brief add the matrix rhs to the matrix rhs
/// @pre lhs and rhs have the same dimensions and
///		 the += operator is defined for type T
/// @post returns a new matrix equal to lhs + rhs
/// @return a new matrix that represents lhs * rhs
///////////////////////////////////////////////////////////////////

#ifndef matrix_h
#define matrix_h

#include <iostream>
#include "vector.h"

template <class T> class GaussianSolver;

template <class T>
class Matrix{
public:
	friend class GaussianSolver<T>;
	
	Matrix(int rows, int columns);
	Matrix(const Matrix<T>& other);
	~Matrix(){
		for (int i = 0; i < this->rows(); ++i){
			delete this->matrix[i];
		}
	}
	
	int rows() const;
	int cols() const;
	
	Vector<T>& operator[](int row) const;
	
	Matrix<T> operator*(const Matrix<T>& rhs) const;
	Vector<T> operator*(const Vector<T>& rhs) const;
	Matrix<T>& operator*=(const T& rhs);
	Matrix<T>& operator+=(const Matrix<T>& rhs);
	
	Matrix<T> transpose() const;
	
	friend std::istream& operator>>(std::istream& in, Matrix<T>& rhs){
		for (int i = 0; i < rhs.rows(); ++i){
			in >> *(rhs.matrix[i]);
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& rhs){
		out << "{";
		for (int i = 0; i < rhs.rows(); ++i){
			out << *rhs.matrix[i];
			if (i+1 < rhs.rows()){
				out << "," << std::endl;
			}
		}
		out << "}" << std::endl;
		return out;
	}
private:
	Array<Vector <T>*> matrix;
};

template <typename T>
Matrix<T>& operator*(const Matrix<T>& lhs, const T& rhs){
	Matrix<T> result(lhs);
	result *= rhs;
	return result;
}

template <typename T>
Matrix<T>& operator+(const Matrix<T>& lhs, const Matrix<T>& rhs){
	Matrix<T> result(lhs);
	result += rhs;
	return result;
}

class InvalidMultiplicationException{
public:
	InvalidMultiplicationException(){}
};

class InvalidAdditionException{
public:
	InvalidAdditionException(){}
};
#include "matrix.hpp"
#endif
