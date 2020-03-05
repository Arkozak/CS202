#include <iostream>
#include <vector>
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 19);

	int x;
	int y;
	std::vector<int> roomnums;
	for (int i = 0; i < 20; i++)
	{
		x = dis(gen);
		y = 0;
		for (auto j : roomnums)
		{
			if (x == j)
			{
				y++;
			}
		}
		if (y > 0)
		{
			i--;
		}
		else
		{
			roomnums.push_back(x);
		}
	}

	for (auto i : roomnums)
	{
		std::cout << i << " ";
	}

	
}