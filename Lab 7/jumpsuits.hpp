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
	const string& _suit1()const { return suit1; };
	const string& _suit2()const { return suit2; };
	const string& _suit3()const { return suit3; };
private:
	string suit1;
	string suit2;
	string suit3;
};

std::ostream& operator<<(std::ostream& os, const Jumpsuits& jumpsuits);

#endif 



