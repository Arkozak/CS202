#ifndef NODES_HPP_
#define NODES_HPP_

#include <string>
using std::string;

class CityNode
{
public:
	CityNode();
	CityNode(unsigned int node, double latY, double lonX);

	void setNode(unsigned int node, double lat, double lon);

	unsigned int getNodeNumber();
	double getLat();
	double getLon();
private:
	unsigned int nodeNumber;
	double latitude;
	double longitude;
	double graphY;
	double graphX;
};

#endif