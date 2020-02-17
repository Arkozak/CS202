#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

unsigned int Factorial(unsigned int number) {
	return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
		
}

bool operator == (const Vector3f& a, const Vector3f& b) { return (a.x == b.x) && (a.y == b.y) && (a.z == b.z); }
bool operator != (const Vector3f& a, const Vector3f& b) { return (a.x == b.x) || (a.y == b.y) || (a.z == b.z); }

class Vector3f
{
public:
	Vector3f()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}

	Vector3f(int m, int n, int o)
	{
		x = m;
		y = n;
		z = o;
	}
	float x;
	float y;
	float z;
};