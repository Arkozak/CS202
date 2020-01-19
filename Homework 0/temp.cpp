#include <string>
using std::strtod;

double c_ctof(const char* str)
{
	double x = strtod(str, nullptr);

	return x * (9.0 / 5.0) + 32.0;
}