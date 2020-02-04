#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

void readfile()
{
	std::fstream doc;
	std::string word;

	doc.open("jumpsuits.txt");

	while (doc >> word)
	{
		std::cout << word << std::endl;
	}

	doc.close();
}



int main()
{
	int x = 0;
	std::string userstr;

	readfile();
	
	std::cout << "Please enter a number n: ";
	std::cin >> x;
	std::cin.ignore();
	std::cout << "Please enter a line: ";
	std::getline(std::cin,userstr);
	std::cout << userstr;

	
}





