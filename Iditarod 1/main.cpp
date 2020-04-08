#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int fib(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}










int main()
{
	int x = 7;

	cout << "The 7th number in the fibonaci sequence is " << fib(7);









	return 0;
}