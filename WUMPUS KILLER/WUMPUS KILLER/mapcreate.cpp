#include "mapcreate.h"

map::map()
{
	fillrooms();
}

void map::fillrooms()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 20);

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
	map::a.num = roomnums[0];
	map::a.adjacent = { roomnums[1], roomnums[20], roomnums[10] };
	map::b.num = roomnums[1];
	map::b.adjacent = { roomnums[2], roomnums[0], roomnums[11] };
	map::c.num = roomnums[2];
	map::c.adjacent = { roomnums[3], roomnums[1], roomnums[12] };
	map::d.num = roomnums[3];
	map::d.adjacent = { roomnums[4], roomnums[2], roomnums[13] };
	map::a.num = roomnums[4];
	map::a.adjacent = { roomnums[5], roomnums[3], roomnums[14] };
	map::b.num = roomnums[5];
	map::b.adjacent = { roomnums[6], roomnums[4], roomnums[15] };
	map::c.num = roomnums[6];
	map::c.adjacent = { roomnums[7], roomnums[5], roomnums[16] };
	map::d.num = roomnums[7];
	map::d.adjacent = { roomnums[8], roomnums[6], roomnums[17] };
	map::a.num = roomnums[8];
	map::a.adjacent = { roomnums[9], roomnums[7], roomnums[18] };
	map::b.num = roomnums[9];
	map::b.adjacent = { roomnums[10], roomnums[8], roomnums[19] };
	map::c.num = roomnums[10];
	map::c.adjacent = { roomnums[11], roomnums[9], roomnums[20] };
	map::d.num = roomnums[11];
	map::d.adjacent = { roomnums[12], roomnums[10], roomnums[0] };
	map::a.num = roomnums[12];
	map::a.adjacent = { roomnums[13], roomnums[11], roomnums[1] };
	map::b.num = roomnums[13];
	map::b.adjacent = { roomnums[14], roomnums[12], roomnums[2] };
	map::c.num = roomnums[14];
	map::c.adjacent = { roomnums[15], roomnums[13], roomnums[3] };
	map::d.num = roomnums[15];
	map::d.adjacent = { roomnums[16], roomnums[14], roomnums[4] };
	map::a.num = roomnums[16];
	map::a.adjacent = { roomnums[17], roomnums[15], roomnums[5] };
	map::b.num = roomnums[17];
	map::b.adjacent = { roomnums[18], roomnums[16], roomnums[6] };
	map::c.num = roomnums[18];
	map::c.adjacent = { roomnums[19], roomnums[17], roomnums[7] };
	map::d.num = roomnums[19];
	map::d.adjacent = { roomnums[20], roomnums[18], roomnums[8] };
	map::d.num = roomnums[20];
	map::d.adjacent = { roomnums[0], roomnums[19], roomnums[9] };
}

int map::batmove(int place)
{
	return 0;
}