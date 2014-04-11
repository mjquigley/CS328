///////////////////////////////////////////////////////////////////
/// @file matrix.hpp
/// @author Matthew Quigley CS328 Section A
/// @brief definitions for the Matrix class
///////////////////////////////////////////////////////////////////

template <class T>
Matrix<T>::Matrix(int rows, int columns){
	this->matrix = Array<Vector<T>* >(rows);
	for (int i = 0; i < rows; ++i){
		this->matrix[i] = new Vector<T>(columns);
	}
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& other){
	this->matrix = Array<Vector<T> *>(other.rows());
	for (int i = 0; i < other.rows(); ++i){
		this->matrix[i] = new Vector<T>(other.cols());
		for (int j = 0; j < other.cols(); ++j){
			(*this)[i][j] = other[i][j];
		}
	}
}

template <class T>
Vector<T>& Matrix<T>::operator[](int row) const{
	return *(this->matrix[row]);
}

template <class T>
int Matrix<T>::rows() const{
	return this->matrix.numElements();
}

template <class T>
int Matrix<T>::cols() const{
	if (this->rows() == 0){
		return 0;
	}
	return this->matrix[0]->numElements();
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) const{
	if (rhs.rows() != this->cols()){
		throw InvalidMultiplicationException();
	}
	Matrix<T> result (this->rows(), rhs.cols());
	for (int i = 0; i < this->rows(); ++i){
		for (int j = 0; j < rhs.cols(); ++j){
			result[i][j] = 0;
			for (int k = 0; k < this->cols(); ++k){
				T l = (*this)[i][k];
				T r = rhs[k][j];
				result[i][j] += l * r;
			}
		}
	}
	return result;
}

template <class T>
Vector<T> Matrix<T>::operator*(const Vector<T>& rhs) const{
	if (rhs.numElements() != this->cols()){
		throw InvalidMultiplicationException();
	}
	Vector<T> result = Vector<T> (this->rows(), this->cols);
	for (int i = 0; i < this->rows(); ++i){
		result[i] = T();
		for (int j = 0; j < this->cols(); ++j){
			for (int k = 0; k < this->cols(); ++k){
				result[i] += (*this)[j][k] * rhs[k];
			}
		}
	}
	return result;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const T& rhs){
	for (int i = 0; i < this->cols(); ++i){
		for (int j = 0; j < this->rows(); ++j){
			(*this)[i][j] = (*this)[i][j] * rhs;
		}
	}
	return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs){
	if (this->rows() != rhs.rows() || this->cols() != rhs.cols()){
		throw InvalidAdditionException();
	}
	for (int i = 0; i < this->rows(); ++i){
		for (int j = 0; j < this->cols(); ++j){
			(*this)[i][j] += rhs[i][j];
		}
	}
}

template <class T>
Matrix<T> Matrix<T>::transpose() const{
	Matrix<T> result (this->cols(), this->rows());
	for (int i = 0; i < this->rows(); ++i){
		for (int j = 0; j < this->cols(); ++j){
			result[j][i] = (*this)[i][j];
		}
	}
	return result;
}
