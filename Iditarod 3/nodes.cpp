#include "nodes.hpp"

//base constructor
CityNode::CityNode() {}

//constructor with perameters
CityNode::CityNode(unsigned int node, double latY, double lonX)
{
	nodeNumber = node;
	latitude = latY;
	longitude = lonX;
}

//setting the node
void CityNode::setNode(unsigned int node, double lat, double lon)
{
	nodeNumber = node;
	latitude = lat;
	longitude = lon;
}



