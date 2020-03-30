//Andrew Kozak 
//Sunday March 29th 
//CS202

#include "complex.hpp"

int main()
{
	cout << Complex() << endl;
	cout << Complex(6, 7) + Complex(6, 2) << endl;

	cout << 1 + Complex(2, 3) << endl;
	cout << Complex(4, 5) + 1 << endl;

	Complex complexa(5, 11);
	Complex complexb(17, 13);

	cout << complexa << endl;
	cout << complexb << endl;

	complexa += complexb;
	cout << complexa << endl;
	

	return 0;
}