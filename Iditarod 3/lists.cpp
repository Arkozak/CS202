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

//determines distance between 2 cities
double CityList::distance(int first, int second)
{
	//x = long y = lat
	double d, x1, x2, y1, y2;
	x1 = getCityLon(first);
	x2 = getCityLon(second);
	y1 = getCityLat(first);
	y2 = getCityLat(second);

	d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

	return d;
}

//sets File name
void CityList::setFileName(string name)
{
	fileName = name;
}

string CityList::getFileName()
{
	return fileName;
}

int CityList::listVectorSpecific(int n)
{
	return cityList[n].getNodeNumber();
}

void CityList::removeCityList(int node)
{
	cityList.erase(cityList.begin() + node);
}

int CityList::getListSize()
{
	return cityList.size();
}