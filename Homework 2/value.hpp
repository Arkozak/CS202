#ifndef VALUE_HPP_
#define VALUE_HPP_

#include <iostream>
using std::cout;
using std::endl;
#include <list>
using std::list;
#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <algorithm>
using std::find;

struct Monster
{
	std::string Name;
	int STR = 0;
	int DEX = 0;
	int CON = 0;
	int INT = 0;
	int WIS = 0;
	int CHA = 0;
};

void queuepush(list<std::shared_ptr<Monster>> enemies, std::shared_ptr<Monster> goblin);

void queuepop(list<std::shared_ptr<Monster>> enemies);

void stackpush(list<std::shared_ptr<Monster>> enemies, std::shared_ptr<Monster> goblin);

void stackpop(list<std::shared_ptr<Monster>> enemies);

void insert(list<std::shared_ptr<Monster>> enemies, std::shared_ptr<Monster> goblin);

bool find(list<std::shared_ptr<Monster>> enemies, std::shared_ptr<Monster> Ogre);

void printenemies(list<std::shared_ptr<Monster>> enemies);


#endif