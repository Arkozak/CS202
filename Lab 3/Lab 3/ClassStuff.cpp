
#include "ClassStuff.hpp"


Jumpsuits::Jumpsuits()
{
	//cout << "Default constructor calling jumpsuits." << endl;
	x = 0;
}

Jumpsuits::Jumpsuits(int y)
{
	//cout << "Parametrized construtor calling jumpsuits." << endl;
	x = y;
}

Jumpsuits::Jumpsuits(string color1, string color2, string color3)
{
	suitcolors.push_back(color1);
	suitcolors.push_back(color2);
	suitcolors.push_back(color3);
}

Jumpsuits::Jumpsuits(Jumpsuits&)
{

}

int Jumpsuits::getX()
{
	return x;
}

void Jumpsuits::addColor(string color)
{
	suitcolors.push_back(color);
}

void Jumpsuits::readback()
{
	cout << "The colors you purchased were: \n";
	for (auto i : suitcolors)
	{
		cout << i << endl;
	}
}
