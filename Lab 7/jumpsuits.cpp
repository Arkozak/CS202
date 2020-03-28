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
