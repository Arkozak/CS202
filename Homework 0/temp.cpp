#include <string>
using std::strtod;
using std::string;
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
 	for (auto i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "temperature"))
		{
			cout << argv[i + 2];
			if (!strcmp(argv[i+1], "--ftoc"))
			{
				cout << " farenheit is equal to " << cpp_ftoc(argv[i + 2]) << " celcius.\n";
			}
			if (!strcmp(argv[i + 1], "--ctof"))
			{
				cout << " farenheit is equal to " << cpp_ftoc(argv[i + 2]) << " celcius.\n";
			}
		}
	}
}