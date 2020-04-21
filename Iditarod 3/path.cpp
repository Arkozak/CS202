#include "path.hpp"

CityPath::CityPath(const int& s) : _size(s) {}

int CityPath::getSize()
{
  return connections.size();
}
int CityPath::getPath(const int& n) const
{
  return connections[n];
}
vector<int> CityPath::getconnections()
{
  return connections;
}

void CityPath::addPath(const int& n)
{
  connections.push_back(n);
}
void CityPath::deletePath(const int& n)
{
  if (connections.size() == 1) {
		connections.erase(connections.begin());
		return;
	}
	connections.erase(connections.begin() + n);
}
void CityPath::deleteAllPaths()
{
  connections.clear();
}
void CityPath::setConnections(vector<int>& vec)
{
	for (auto a : vec)
	{
		connections.push_back(a);
	}
}
