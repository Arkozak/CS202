#include "complex.hpp"


Complex::Complex(double real, double imaginary): x(real), i(imaginary) {}

Complex Complex::operator+(const Complex& complex)
{
	return Complex(x + complex.x, i + complex.i);
}

Complex& Complex::operator+=(const Complex complex)
{
	*this = *this + complex;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	//r + i
	os << complex.xreturn();
	os << " + i ";
	os << complex.ireturn();
	return os;
}

