
#define CATCH_CONFIG_MAIN

#include "value.hpp"
#include "Catch.hpp"


list<std::shared_ptr<Monster>> enemies;

TEST_CASE("TESTING VALUE.HPP", "[data]")
{
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


	SECTION("QUEUE")
	{
		queuepush(enemies, goblin);
		REQUIRE(enemies.back() == goblin);

		queuepop(enemies);
		REQUIRE(enemies.front() != goblin);
	}

	SECTION("STACK")
	{
		stackpush(enemies, goblin);
		REQUIRE(enemies.back() == goblin);

		stackpop(enemies);
		REQUIRE(enemies.back() != goblin);
	}

	SECTION("INSERT AND FIND")
	{
		insert(enemies,goblin);
		REQUIRE(enemies.front() == goblin);

		find(enemies, Ogre);
		REQUIRE(find(enemies, Ogre) == true);
	}

	printenemies;
}
