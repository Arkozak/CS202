#ifndef CITYPATH_HPP_
#define CITYPATH_HPP_
#include <iostream>
#include <vector>
using std::vector;
#include "nodes.hpp"

class CityPath
{
public:
  CityPath(const int& s);
  CityPath() : _size(0) 
  {
  }
  CityPath(CityPath& copy)
  { 
	  connections = copy.connections;
  }

  int getSize();
  int getPath(const int& n) const;
  vector<int> getconnections();

  void addPath(const int& n);
  void deletePath(const int& n);
  void deleteAllPaths();
  void setConnections(vector<int>& vec);

  int size() const 
  { 
	  return connections.size();
  }

private:
  vector<int> connections;
  int _size;
};

#endif