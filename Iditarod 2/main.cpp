#include <iostream>
using std::cout;
using std::endl;


int ack(int n, int j)
{
	if (n == 0)
	{
		return j + 1;
	}
	if ((n > 0) && (j == 0))
	{
		return ack(n - 1, 1);
	}
	if ((n > 0) && (j > 0))
	{
		return ack(n - 1, ack(n, j - 1));
	}
}


int main()
{
	cout << ack(4, 7);


	return 0;
}