#include "nodes.hpp"

//base constructor
CityNode::CityNode() {}

//constructor with perameters
CityNode::CityNode(unsigned int node, double lat, double lon)
{
	nodeNumber = node;
	latitude = lat;
	longitude = lon;
	graphY = lat;
	graphX = lon;
}

//setting the node
void CityNode::setNode(unsigned int node, double lat, double lon)
{
	nodeNumber = node;
	latitude = lat;
	longitude = lon;
	graphY = lat;
	graphX = lon;
}

//the following 3 functions return what they are labeled as
unsigned int CityNode::getNodeNumber()
{
	return nodeNumber;
}

double CityNode::getLat()
{
	return latitude;
}

double CityNode::getLon()
{
	return longitude;
}

