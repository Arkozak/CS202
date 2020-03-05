#include "main.h"

#define MAPCREATE_H
#ifdef MAPCREATE_H

struct room
{
	int roomarray[20][3];
};

class map
{
public:
	map();
	void printplayer();
	void moveplayer();
	bool dead();
	void detect();
private:
	void fillrooms();
	int batmove();
	room layout;
	int player;
	int wumpus;
	int bats1;
	int bats2;
	int pit1;
	int pit2;
	int arrowcount = 5;
};

#endif