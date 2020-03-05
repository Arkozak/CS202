#include "mapcreate.h"
#include "main.h"

int main()
{
	map wump;
	std::string answer;

	while (0 == 0)
	{
		wump.printplayer();
		wump.detect();
		std::cout << "Would you like to move or shoot? ";
		std::cin >> answer;

		if (answer == "move")
		{
			wump.moveplayer();
		}

		if (wump.dead() == 1)
		{
			return 0;
		}
		

		std::cout << "\n";
	}

	
}