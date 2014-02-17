template <class T>
int compare (const T& t1, const T& t2){
	if (t1 < t2) return -1;
	if (t2 < t1) return 1;
	return 0;
}
template <>
int compare <const char*>(const char* const & s1, const char* const & s2){
	return strcmp(s1, s2);
}

class Point{
public:
	Point(){}
	...
	float& getX();
	float getX() const;	//this version will keep const compliance
	//Having both version, the compiler will choose the appropriate one
}

//What if:
Point a(1,2);
const Point ORIGIN(0, 0);

Point a();
a.do_something();


Point(int x, int y): x(x), y(y){}

class Type{
public:
	friend ostream& operator<<(ostream& out, const Type& t);
}

ostream& operator<<(ostream& out, const Type& t){
	os << ...
	return out;
}


//z = a + bi
class Complex{
private:
	float m_real, m_imaginary;
public:
	friend Complex operator+(const Complex & lhs, const Complex & rhs);
	Complex& operator+=(const Complex& rhs);
}

Complex operator+(const Complex& lhs, const Complex& rhs){
	Complex result(lhs);
	return result += rhs;
}

Complex& Complex::operator+=(const Complex& rhs){
	m_real += rhs.m_real;
	m_imaginary += rhs.m_imaginary;
	return (*this);
}

