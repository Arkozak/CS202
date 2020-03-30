#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>

class Complex
{
public:
	//Constructors
	Complex() {}
	Complex(double real, double imaginary = 0);
	//Operators
	Complex operator+(const Complex& complex);
	Complex& operator+=(const Complex complex);
	//Returns
	double xreturn() const { return x; }
	double ireturn() const { return i; }
private:
	//Variables
	double x = 0;
	double i = 0;
};

//Adding operator
inline Complex operator+(double realv, const Complex imaginaryv)
{
	return Complex(realv + imaginaryv.xreturn(), imaginaryv.ireturn());
}

std::ostream& operator<<(std::ostream& os, const Complex& complex);

#endif