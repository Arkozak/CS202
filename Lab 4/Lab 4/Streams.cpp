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

void append(int x, std::string userstr)
{
	std::fstream doc;
	doc.open("jumpsuits.txt", std::ios_base::app);

	for (int i = 0; i < x; i++)
	{
		doc << "\n" << userstr;
	}
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

	append(x, userstr);
}




