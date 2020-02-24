#include "fooooo.hpp"

void foo()
{
	std::cout << "NOT THE NAMESPACE FOO!!!\n";
}

int main()
{
	foo();
	fooooo::foo();
	foo();

}