#include <sstream>
#include <iostream>
#include <fstream>

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
	readfile();


}




