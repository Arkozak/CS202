#ifndef LISTS_HPP_
#define LISTS_HPP_

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "nodes.hpp"
#include <cmath>

class CityList
{
public:
	CityList();
	CityList(CityNode node);

	void setCityNode(CityNode node);
	CityNode getCityNode(int node);
	double getCityLat(int node);
	double getCityLon(int node);
	int getCityNodeInt(int node);

	void printCityNode(unsigned int node);
private:
	vector<CityNode> cityList;
	CityNode node;
};

#endif