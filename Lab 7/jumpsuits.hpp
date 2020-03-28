#ifndef jumpsuits_HPP
#define jumpsuits_HPP

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
	void suit1add(string);
	void suit2add(string);
	void suit3add(string);
private:
	string suit1;
	string suit2;
	string suit3;
};



#endif 



