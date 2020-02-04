#include <sstream>
#include <iostream>
#include <fstream>

void readfile()
{
	std::fstream doc;
	std::ofstream("jumpsuites.txt");
	std::string word;

	while (doc >> word)
	{
		std::cout << word << std::endl;
	}
}

int main()
{
	std::ifstream("jumpsuites.txt");
	std::ofstream("jumpsuites.txt");




}