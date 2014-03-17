#ifndef chebyshevPolynomial_h
#define chebyshevPolynomial_h
#include "polynomial.h"

template <class T>
class ChebyshevPolynomial{
public:
	ChebyshevPolynomial(int n){
		Array<T> coefficients0(1);
		coefficients0[0] = 1;
		Polynomial t0 = Polynomial(coefficients0);
		Array<T> coefficients1(1);
		coefficients1[0] = 0;
		coefficients1[1] = 1;
		Polynomial t1 = Polynomial(coefficients1);
		poly_1 = t0;
		poly = t1;
		Polynomial temp;
		for (int i = 0; i <=n; ++i){
			temp = poly;
			poly *= 2;
			poly.multiplyByPowerOfX(1);
			poly -= poly_1;
			poly_1 = temp;
		}
	}
	operator()(T x){
		return poly(x);
	}
private:
	Polynomial poly;
};

#endif
