#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include "nodes.hpp"
#include "lists.h"
#include "solver.hpp"

void readTSP(string fileName, CityNode& node, CityList& city)
{
	ifstream ifile(fileName);
	//Throw error 
	if (!ifile)
	{
		cout << "Couldn't open file." << endl;
	}
	else
	{
		city.setFileName(fileName);
		string line;
		bool loop = true;

		while (loop)
		{
			if (!ifile)
			{
				if (ifile.eof())
				{
					loop = false;
				}
				else
				{
					loop = true;
				}
			}
			else
			{
				getline(ifile, line);
				string nodeStart = "NODE_COORD_SECTION";

				//Begin node list for city
				if (line == nodeStart)
				{
					bool loop1 = true;
					while (loop1)
					{
						//EOF Help
						if (line == "EOF")
						{
							loop1 = false;
							loop = false;
						}
						else
						{
							loop1 = true;
						}
						getline(ifile, line);

						//Testing if line is an int
						istringstream iss(line);
						int val;
						iss >> val;

						// Setting Node number
						if (iss)
						{
							istringstream iss1(line);
							
							unsigned int val1;
							double val2;
							double val3;

							iss1 >> val1;
							iss1 >> val2;
							iss1 >> val3;
							
							node.setNode(val1, val2, val3);
							
							city.setCityNode(node);
						}
					}
				}
			}
		}
	}
}

int main()
{
	CityNode node0(907, 333, 8000);

	//Make CityList 1
	CityList d;
	readTSP("d1291.tsp", node0, d);

	//Make CityList 2
	CityList fl;
	readTSP("fl1400.tsp", node0, fl);

	//Make CityList 2
	CityList nrw;
	readTSP("nrw1379.tsp", node0, nrw);
	
	//Make CityList 4
	CityList pla;
	readTSP("pla85900.tsp", node0, pla);
	
	//Make CityList 5
	CityList rl;
	readTSP("rl5915.tsp", node0, rl);
	
	cout << "Node rl(1): ";
	rl.printCityNode(1);

	cout << "Distance from node 1 and node 20 in rl: " << rl.distance(1, 2) << endl;

	TspSolver testSolve;
	cout << "Greedy solution \n\n\n";
	testSolve.solveG(rl);

	cout << "Random solution \n\n\n";
	testSolve.solveR(rl);
	


	return 0;
}