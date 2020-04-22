#include "solver.hpp"

int TspSolver::RandInt(int high, int low)
{
	std::random_device rd;
	std::mt19937 gen1(rd());
	std::uniform_int_distribution<int> dist(low, high);
	return dist(gen1);
}

void TspSolver::solveG(CityList& list)
{
  CityPath a;
  CityPath b;
  double dist = 0;

  //Filling unmarked path
  for (int i = 0; i < list.getListSize(); i++)
  {
	  b.addPath(i);
  }

  //Random starting city
  int startNode = RandInt(list.getListSize() - 1, 0);
  a.addPath(startNode);

  b.deletePath(startNode);

  int smallest;
  int del;
  // Loop for all nodes
  for (int i = 0; i < list.getListSize(); i++)
  {
    dist = 1e12;

    //If last city
    if (b.size() == 1)
    {
      a.addPath(b.getPath(0));
      b.deletePath(0);
      break;
    }

    //Find closest city comparing all cities remaining (unmarked)
    for(auto z = 0; z < b.getSize(); z++)
    {
      if (dist > list.distance(a.getPath(i), b.getPath(z)))
      {
        dist = list.distance(a.getPath(i), b.getPath(z));

        //Smallest city found
        smallest = b.getPath(z);
        //Delete the found city
        del = z;
      }
    }

    a.addPath(smallest);
    b.deletePath(del);

  }

  a.addPath(a.getPath(0));

  dist = 0;
  cout << "Path traveled: ";
  for (int i = 0; i < a.size() - 1; i++)
  {
    dist = dist + list.distance(a.getPath(i), a.getPath(i+1));
    cout << a.getPath(i) << " ";
  }
  cout << a.getPath(a.size() - 1) << endl;
  cout << "Total distance: " << dist << endl;
}

void TspSolver::solveR(CityList& list)
{
	CityPath a;
	CityPath b;
	vector<int> temp;
	vector<int> finalVec;
	double dist = 0;
	double bestDist = 1e12;
	int m = 10;

	for (int i = 0; i < m; i++)
	{
		temp.clear();
		dist = 0;
		b.deleteAllPaths();

		//Fill unmarked path
		for (int i = 0; i < list.getListSize(); i++)
		{
			b.addPath(i);
		}
		temp.clear();
		int startNode = RandInt(list.getListSize() - 1, 0);
		temp.push_back(startNode);
		b.deletePath(startNode);

		//While cities unmarked remain
		while (b.size() != 0)
		{
			int startNode = RandInt( b.size() - 1, 0);
			temp.push_back(b.getPath(startNode));
			b.deletePath(startNode);
		}

		//Starting city is also ending city
		temp.push_back(temp[0]);

		//Find distance traveled
		for (auto i = 0; i < temp.size() - 1; i++)
		{
			dist = dist + list.distance(temp[i], temp[i + 1]);
		}

		if (dist < bestDist)
		{
			bestDist = dist;
			finalVec = temp;
		}
	}

	a.setConnections(finalVec);
	dist = 0;
	cout << "Path traveled: ";
	for (int i = 0; i < a.size() - 1; i++)
	{
		dist = dist + list.distance(a.getPath(i), a.getPath(i + 1));
		cout << a.getPath(i) << " ";
	}
	cout << a.getPath(a.size() - 1) << endl;
	cout << "Total distance: " << dist << endl;
}