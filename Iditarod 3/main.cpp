#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include "nodes.hpp"
#include "lists.h"
#include "solver.hpp"
#include "svg.hpp"

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
	TspSolver solve;

	cout << "NRW\n";
	CityList nrw;
	readTSP("nrw1379.tsp", node0, nrw);
	CityPath svgnrw;
	solve.solveG(nrw, svgnrw);
	cout << "Generating Greedy SVG Output\n";
	svgGraph(nrw, svgnrw, "nrw1379.tspGreedy.svg");
	solve.solveR(nrw, svgnrw);
	cout << "Generating Randomly SVG Output\n";
	svgGraph(nrw, svgnrw, "nrw1379.tspRandom.svg");

	cout << "RL:\n";
	CityList rl;
	readTSP("rl5915.tsp", node0, rl);
	CityPath svgrl;
	solve.solveG(rl, svgrl);
	cout << "Generating Greedy SVG Output\n";
	svgGraph(rl, svgrl, "rl5915.tspGreedy.svg");
	solve.solveR(rl, svgrl);
	cout << "Generating Randomly SVG Output\n";
	svgGraph(rl, svgrl, "rl5915.tspRandom.svg");

	cout << "FL:\n";
	CityList fl;
	readTSP("fl1400.tsp", node0, fl);
	CityPath svgfl;
	solve.solveG(fl, svgfl);
	cout << "Generating Greedy SVG Output\n";
	svgGraph(fl, svgfl, "fl1400.tspGreedy.svg");
	solve.solveR(fl, svgfl);
	cout << "Generating Randomly SVG Output\n";
	svgGraph(fl, svgfl, "fl1400.tspRandom.svg");

	cout << "D:\n";
	CityList d;
	readTSP("d1291.tsp", node0, d);
	CityPath svgd;
	solve.solveG(d, svgd);
	cout << "Generating Greedy SVG Output\n";
	svgGraph(d, svgd, "d1291.tspGreedy.svg");
	solve.solveR(d, svgd);
	cout << "Generating Randomly SVG Output\n";
	svgGraph(d, svgd, "d1291.tspRandom.svg");

	cout << "PR:\n";
	CityList pr;
	readTSP("pr1002.tsp", node0, pr);
	CityPath svgpr;
	solve.solveG(pr, svgpr);
	cout << "Generating Greedy SVG Output\n";
	svgGraph(pr, svgpr, "pr1002.tspGreedy.svg");
	solve.solveR(pr, svgpr);
	cout << "Generating Randomly SVG Output\n";
	svgGraph(pr, svgpr, "pr1002.tspRandom.svg");
	return 0;
}