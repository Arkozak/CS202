#include "value.hpp"

void queuepush(list<std::shared_ptr<Monster>> enemies, const Monster& goblin, const Monster& bugbear, const Monster& Ogre)
{
	enemies.push_back(goblin);
	enemies.push_back(bugbear);
	enemies.push_back(Ogre);
}

void queuepop(list<std::shared_ptr<Monster>> enemies)
{
	enemies.pop_front();
}

void stackpush(list<std::shared_ptr<Monster>> enemies, const Monster& goblin)
{
	enemies.push_back(goblin);
}

void stackpop(list<std::shared_ptr<Monster>> enemies)
{
	enemies.pop_back();
}

void insert(list<std::shared_ptr<Monster>> enemies, const Monster& goblin)
{
	list<std::shared_ptr<Monster>> ::iterator it;
	it = enemies.begin();
	++it;
	enemies.insert(it, goblin);
}

void find(list<std::shared_ptr<Monster>> enemies, const Monster& Ogre)
{
	list<std::shared_ptr<Monster>> ::iterator it;
	it = std::find(enemies.begin(), enemies.end(), Ogre);

	if (it != enemies.end())
	{
		std::cout << "Ogre stats exists in list.\n\n";
	}
}

void printenemies(list<std::shared_ptr<Monster>> enemies)
{
	list<std::shared_ptr<Monster>> ::iterator it;
	for (it = enemies.begin(); it != enemies.end(); ++it)
	{
		shared_ptr<Monster> pointer(*it);
		cout << "NAME: " << pointer->Name << "\n";
		cout << "STR: " << pointer->STR << "\n";
		cout << "DEX: " << pointer->DEX << "\n";
		cout << "CON: " << pointer->CON << "\n";
		cout << "INT: " << pointer->INT << "\n";
		cout << "WIS: " << pointer->WIS << "\n";
		cout << "CHA: " << pointer->CHA << "\n";
		cout << endl;
	}
}

