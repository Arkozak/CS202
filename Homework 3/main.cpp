#include <iostream>
using std::cout;
using std::cin;
using std::pair;
#include <fstream>
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;

bool LineToTokens(const string& line, vector<string>& tokens)
{
	string token;
	
	for (auto i : line)
	{
		if (i == ' ')
		{
			tokens.push_back(token);
			token = "";
		}
		else
		{
			token = token + i;
		}
	}
	return 0;
}

bool ReadLine(std::istream& is, vector<string>& tokens, vector<pair<int, int>>& linecols)
{

}

void PrintTokens(std::ostream& os, const vector<std::string>& tokens, const vector<pair<int, int>>& linecols)
{

}

int main(int argc, char* argv[])
{	
	string line = argv[1];
	vector<string> tokens;
	vector<pair<int, int>> linecols;

	std::ifstream file;
	file.open("text.txt");
	
	if (!file.eof())
	{
		while (getline(file, line))
		{
			LineToTokens(line, tokens);
		}
	}
	

	file.close();
	return 0;
}