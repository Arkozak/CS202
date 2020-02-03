#include "value.hpp"

void queuepush(list<std::shared_ptr<Monster>> enemies, std::shared_ptr<Monster> goblin)
{
	enemies.push_back(goblin);

}

void queuepop(list<std::shared_ptr<Monster>> enemies)
{
	enemies.pop_front();
}

void stackpush(list<std::shared_ptr<Monster>> enemies, std::shared_ptr<Monster> goblin)
{
	enemies.push_back(goblin);
}

void stackpop(list<std::shared_ptr<Monster>> enemies)
{
	enemies.pop_back();
}

void insert(list<std::shared_ptr<Monster>> enemies, std::shared_ptr<Monster> goblin)
{
	list<std::shared_ptr<Monster>> ::iterator it;
	it = enemies.begin();
	enemies.insert(it, goblin);
}

bool find(list<std::shared_ptr<Monster>> enemies, std::shared_ptr<Monster> Ogre)
{
	list<std::shared_ptr<Monster>> ::iterator it;
	it = std::find(enemies.begin(), enemies.end(), Ogre);

	if (it != enemies.end())
	{
		std::cout << "Ogre stats exists in list.\n\n";
		return true;
	}
	return false;
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

