#include "lists.h"

//base constructor
CityList::CityList() {}

//constructor with parameters
CityList::CityList(CityNode node)
{
	cityList.push_back(node);
}

//adding a node
void CityList::setCityNode(CityNode node)
{
	cityList.push_back(node);
}

//the next 4 functions return their respected values
CityNode CityList::getCityNode(int node)
{
	return cityList[node];
}

int CityList::getCityNodeInt(int node)
{
	return cityList[node].getNodeNumber();
}

double CityList::getCityLat(int node)
{
	return cityList[node].getLat();
}

double CityList::getCityLon(int node)
{
	return cityList[node].getLon();
}

//prints specific nodes
void CityList::printCityNode(unsigned int node)
{
	cout <<  " Node: " << cityList[node - 1].getNodeNumber() 
		 << " Lat: "<< cityList[node - 1].getLat() 
		 << " Lon: "<< cityList[node - 1].getLon() << endl;
}