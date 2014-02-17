class Bell{
private:
	float m_a, b_b;
public:
	bell(float a, float b);
	float operator()(float x){
		return m_a/(m_b + x * x);
	}
};

class A {
public:
	//stuff
	class B{
	public:
		int b_val;
		void f();
	};
};

void A::B::f(){
	...
}

int index_of_min(const Array<float>& a){
	...
	return num_index;	//returns index of min. element in a
}

float& min_element(Array<float>& a){
	return a[index_of_min(a)];
}

Array<float> a(10);
...
min_element(a) = 0;