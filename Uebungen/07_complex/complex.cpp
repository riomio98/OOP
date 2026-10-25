/*
 * complex.cpp
 *
 *  Created on: 22.10.2026
 *      Author: n3034770
 */
#include <iostream>
 using namespace std;
 
 
class Complex{
private:
	double _real;
	double _imag;
public:
	Complex(double real, double imag)
		:_real(real), _imag(imag)
		{
		}
	friend Complex operator+(const Complex& a, const Complex& b);
	Complex operator*(const Complex& b)
	{
		double r = this->_real * b._real - this->_imag * b._imag;
		double i = this->_real * b._imag + this->_imag * b._real;
		Complex ret = {r,i};
		return ret;
	}
	Complex& operator+=(Complex& other)
	{
		this->_real += other._real;
		this->_imag += other._imag;
		return *this;
	}


	double real() const
	{
		return _real;
	}
	double imag() const
	{
		return _imag;
	}
};

Complex operator+(const Complex& a, const Complex& b)
{
	return Complex(a._real + b._real, a._imag + b._imag);
}




int main(){
	
	Complex a(1,2);
	Complex b(3,4);
	
	Complex c = a+b;
	
	cout << "a: " << a.real() << " + " << a.imag() << "i" << endl;
	cout << "b: " << b.real() << " + " << b.imag() << "i" << endl;
	cout << "c: " << c.real() << " + " << c.imag() << "i" << endl;
	
	Complex d = a*b;

	cout << "d: " << d.real() << " + " << d.imag() << "i" << endl;
	
	Complex e(6,2);
	e+= a;
	cout << "d: " << e.real() << " + " << e.imag() << "i" << endl;

	return 0;
}


