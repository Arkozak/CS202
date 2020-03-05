#include "main.h"

#define MAPCREATE_H
#ifdef MAPCREATE_H

struct room
{
	int num = 0;
	std::vector<int> adjacent;
	bool wump = 0;
	bool pit = 0;
	bool bats = 0;
};

class map
{
public:
	map();
private:
	void fillrooms();
	int batmove(int place);
	int place;
	room a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t;
};

#endif