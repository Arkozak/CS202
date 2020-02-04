#ifndef CLASSSTUFF_HPP
#define CLASSSTUFF_HPP

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;

class Jumpsuits {
public:
	Jumpsuits();
	Jumpsuits(int x);
	Jumpsuits(string color1, string color2, string color3);
	Jumpsuits(Jumpsuits&);
	int getX();
	void addColor(string color);
	void readback();
private:
	int x;
	vector<string> suitcolors;
};

#endif 
