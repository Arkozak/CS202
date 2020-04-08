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

int fib_loop(int n)
{
	if (n <= 1)
	{
		return n;
	}
	int x = 1;
	int y = 1;
	for (auto i = 2; i < n; i++)
	{
		int temp = x;
		x = x + y;
		y = temp;
	}
	return x;
}

int fact(int n)
{
	if (n > 1)
	{
		return n * fact(n - 1);
	}
	else
	{
		return 1;
	}
}






int main()
{
	int x = 7;

	cout << "The 7th number in the fibonaci sequence is " << fib(x);

	cout << "The 7th number in the fibonaci sequence is " << fib_loop(x);

	cout << "The factorial of 7 is " << fact(x);






	return 0;
}