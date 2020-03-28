#include "jumpsuits.hpp"


Jumpsuits::Jumpsuits()
{
	cout << "Default constructor calling jumpsuits." << endl;
}

Jumpsuits::Jumpsuits(int y)
{
	cout << "Parametrized construtor calling jumpsuits." << endl;
}

void Jumpsuits::suit1add(string tempstr)
{
	suit1 = tempstr;
}


void Jumpsuits::suit2add(string tempstr)
{
	suit2 = tempstr;
}


void Jumpsuits::suit3add(string tempstr)
{
	suit3 = tempstr;
}
 /*
const string& Jumpsuits::_suit1()
{
	return suit1;
}

const string& Jumpsuits::_suit2()
{
	return suit2;
}

const string& Jumpsuits::_suit3()
{
	return suit3;
}
*/
std::ostream& operator<<(std::ostream& os, const Jumpsuits& jumpsuits)
{
	os << "Color 1: " << jumpsuits._suit1() << std::endl;
	os << "Color 2: " << jumpsuits._suit2() << std::endl;
	os << "Color 3: " << jumpsuits._suit3();
	return os;
}
