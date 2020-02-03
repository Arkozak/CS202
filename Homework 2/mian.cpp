
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
	int STR=0;
	int DEX=0;
	int CON=0;
	int INT=0;
	int WIS=0;
	int CHA = 0;
};


void showlist(list<std::shared_ptr<Monster>> list2use)
{
	list<std::shared_ptr<Monster>> ::iterator it;
	for (it = list2use.begin(); it != list2use.end(); ++it)
	{
		shared_ptr<Monster> pointer(*it);
		cout << "NAME: " << pointer->Name << "\n";
		cout << "STR: " << pointer->STR  << "\n";
		cout << "DEX: " << pointer->DEX  << "\n";
		cout << "CON: " << pointer->CON  << "\n";
		cout << "INT: " << pointer->INT  << "\n";
		cout << "WIS: " << pointer->WIS  << "\n";
		cout << "CHA: " << pointer->CHA  << "\n";
		cout << endl;
	}
}

int main()
{
	list<std::shared_ptr<Monster>> enemies;


	std::shared_ptr<Monster> goblin(new Monster);
	goblin->Name = "Goblin";
	goblin->STR = 8;
	goblin->DEX = 14;
	goblin->CON = 10;
	goblin->INT = 10;
	goblin->WIS = 8;
	goblin->CHA = 8;

	std::shared_ptr<Monster> bugbear(new Monster);
	bugbear->Name = "Bugbear";
	bugbear->STR = 15;
	bugbear->DEX = 14;
	bugbear->CON = 13;
	bugbear->INT = 8;
	bugbear->WIS = 11;
	bugbear->CHA = 9;

	std::shared_ptr<Monster> Ogre(new Monster);
	Ogre->Name = "Ogre";
	Ogre->STR = 19;
	Ogre->DEX = 8;
	Ogre->CON = 16;
	Ogre->INT = 5;
	Ogre->WIS = 7;
	Ogre->CHA = 7;

	enemies.push_back(goblin);
	enemies.push_back(bugbear);
	enemies.push_back(Ogre);

	showlist(enemies);
	
	enemies.pop_front();
	cout << "Popping front:\n";
	showlist(enemies);

	cout << "Pushing back:\n";
	enemies.push_back(goblin);
	showlist(enemies);

	cout << "Popping back:\n";
	enemies.pop_back();
	showlist(enemies);



	return 0;

}