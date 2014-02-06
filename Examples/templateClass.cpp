//array.h
template<class T/*, class U*/>
class Array{
	public:
		Array();
		Array(const int size);
		Array(const Array<T>& source);
		~Array();
		T& operator[](const int i);
		int getSize() const;
		Array<T>& operator=(const Array<T>& source);
		Array<T>& operator=(const T& f);
		void setSize(const int size);
	private:
		int m_size;
		T* ptr_to_data;
		void arrayCopy(const Array<T>& source);
};
#include "array.hpp"

//array.hpp
template<class T>
Array<T>::Array(){
	m_size = 0;
	ptr_to_data = 0;
}
...
//Pre: the '=' operator must be defined for T_type
//template function example
template <typename T_type>
void swap(T_type& t1, T_type2& t2){
	T_type temp = t1;
	t1 = t2;
	t2 = temp;
	//or
	t1^=t2^=t1^=t2
	//^= is the XOR operator
}


//Exception Handling
class RangeErr{
	public:
		RangeErr();
		int badSubscr(int i);
	private:
		int subscr
}

classSizeErr{
	public:
		sizeErr(int i);
	private:
		int subscr;
}

//3 functions of the array class are changed

template<class T>
Array<T>::Array(const int size){
	if (n < 0){
		throw SizeErr(n);
	}
	m_size = n;
	ptr_to_data = T[n];
}

template<class T>
T& Array<T>::operator[](const int i){
	if (i < 0 || i > m_size){
		throw RangeErr(i);
	}
	return ptr_to_data[i];
}

template<class T>
void Array<T>::setSize(const int n){
	if (n != m_size){
		if (n < 0){
			throw sizeErr(n);
		}
		m_size = n;
		ptr_to_data = T[n];
	}
}
...

try{
	int n;
	cin >> n;
	Array<float> array(n);
	...
	int j;
	cin >> j;
	float f = arrayj[];
} catch (RangeErr e){
	cerr<<"Subscript is out of Range: "<<e.badSubscr()<<endl;
} catch (SizeErr e){
	cerr<<"Size is less than 0"<<endl;
}