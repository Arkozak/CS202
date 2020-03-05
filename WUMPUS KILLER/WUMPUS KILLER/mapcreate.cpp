#include "mapcreate.h"

map::map()
{
	//creating everything and running test outputs
	fillrooms();
	for (int i = 0; i < 20; i++)
	{
		std::cout << i << ":    ";
		for (int j = 0; j < 3; j++)
		{
			std::cout << map::layout.roomarray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << map::bats1 << " " << map::bats2 << " " << map::pit1 << " " << map::pit2 << " " << map::wumpus << " " << map::player << " ";
}

void map::fillrooms()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0,19);


	//Linking the rooms together
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
	for (int i = 0; i < 10; i++)
	{
		roomnums.push_back(roomnums[i]);
	}


	//Creating the rooms
	for (int i = 0; i < 20; i++)
	{
		if (i == 0)
		{
			map::layout.roomarray[roomnums[i]][0] = roomnums[19];
			map::layout.roomarray[roomnums[i]][1] = roomnums[1];
			map::layout.roomarray[roomnums[i]][2] = roomnums[10];
		}
		else if (i == 19)
		{
			map::layout.roomarray[roomnums[i]][0] = roomnums[18];
			map::layout.roomarray[roomnums[i]][1] = roomnums[0];
			map::layout.roomarray[roomnums[i]][2] = roomnums[9];
		}
		else
		{
			map::layout.roomarray[roomnums[i]][0] = roomnums[i-1];
			map::layout.roomarray[roomnums[i]][1] = roomnums[i+1];
			map::layout.roomarray[roomnums[i]][2] = roomnums[i+10];
		}
	}



	//Determining where the bats, wumpus, pits, and player are
	std::vector<int> filler;
	for (int i = 0; i < 6; i++)
	{
		x = dis(gen);
		y = 0;
		for (auto j : filler)
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
			filler.push_back(x);
		}
	}
	map::player = filler[0];
	map::wumpus = filler[1];
	map::pit1 = filler[2];
	map::pit2 = filler[3];
	map::bats1 = filler[4];
	map::bats2 = filler[5];
}

int map::batmove()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 19);

	map::player = dis(gen);
	return 0;
}