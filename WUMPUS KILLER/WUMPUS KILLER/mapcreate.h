#include "main.h"

#define MAPCREATE_H
#ifdef MAPCREATE_H

struct room
{
	int room;
	std::vector<int> adjacent;
	bool wump;
	bool pit;
	bool bats;
};

class map
{
public:
	map();
private:
	void batmove();

};

#endif