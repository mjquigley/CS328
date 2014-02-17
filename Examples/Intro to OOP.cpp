//Line.hpp
class Point;

class Life{
	private:
		float m_a, m_b, m_c;
	public:
		Line(Point pt1, Point pt2);
		Line(Point pt, float xdir, float ydir);
		float dist(Point pt) const;
		static float parallel_tolerance;
};

//Line.cpp

float Line::dist(Point pt) const{
	return abs(m_a * pt.getx() + m_b * pt.gety() + m_c) / sqrt(m_a * m_a + m_b * m_b);
}

float Line::parallel_tolerance = .01745;

//Array.hpp

class Array{
	public:
		Array(const int size);			//pass array size
		Array();						//default empty
		Array(const Array& source);		//copy constructor
		~Array();
		float& operator[] const int i);	//subscripting
		int getSize() const;
		Array& operator=(const Array& source);	//copy assignment
		void setSize(const int size);
	private:
		int m_size;
		float* ptr_to_data;
		void arrayCopy(const Array& source);
};

//Array.cpp

Array::Array(const int size){
	m_size = size;
	ptr_to_data = new float[size];
}
Array::Array(){
	m_size = 0;
	ptr_to_data = NULL;
}
Array::Array(const Array& source){
	m_size = source.m_size;
	ptr_to_data = new float[m_size];
	arrayCopy(source);
}
void Array::arrayCopy(const Array& source){
	/*float* p = ptr_to_data + m_size;
	float* q = Source.ptr_to_data + m_size;
	while (p > ptr_to_data){
		*--p = *--q;
	}*/
	for (int i=0; i<m_size; i++){
		ptr_to_data[i] source.ptr_to_data[i];
	}
}
~Array::Array(){
 delete [] ptr_to_data;
}
float& Array::operator[](const int i){
	return ptr_to_data[i];
}
Array& Array::operator=(const Array& source){
	if (ptr_to_data != source.ptr_to_data){
		setSize(source.m_size);
		arrayCopy(source);
	}
	return *this;
}
void Array::setSize(const int size){
	if (size != m_size){
		delete[] ptr_to_data;
		m_size = size;
		ptr_toData = new float[size];
	}
}



