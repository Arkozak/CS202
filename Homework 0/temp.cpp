#include <string>
using std::strtod;
#include <iostream>
using std::cout; 
using std::endl;

double c_ctof(const char* str)
{
	double x = strtod(str, nullptr);

	return x * (9.0 / 5.0) + 32.0;
}

double cpp_ftoc(const char* str)
{
	double x = strtod(str, nullptr);

	return (x -32.0) * (5.0 / 9.0);
}

int main(int argc, char* argv[])
{
	cout << c_ctof(argv[1]);
}