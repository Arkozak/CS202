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
#include <iomanip>
using std::setw;

bool LineToTokens(const string& line, vector<string>& tokens)
{
	string token;
	for (auto i = 0; i < line.size();i++)
	{
		if (line.empty())
		{
			tokens.push_back("");
			return 0;
		}
		if (i == line.size() - 1)
		{
			token = token + line[i];
			tokens.push_back(token);
			return 0;
		}
		if (line[i] == ' ')
		{
			tokens.push_back(token);
			token.clear();
		}
		else
		{
			token = token + line[i];
		}
	}
	return 0;
}

bool ReadLine(std::istream& is, vector<string>& tokens, vector<pair<int, int>>& linecols)
{
	int l;
	int c = 1;
	if (linecols.empty())
	{
		l = 1;
	}
	else
	{
		l = linecols[linecols.size() - 1].first + 1;
	}

	for (auto i : tokens)
	{
		linecols.push_back(std::make_pair(l, c));
		c = c + i.size() + 1;
	}
	return 0;
}

void PrintTokens(std::ostream& os, const vector<std::string>& tokens, const vector<pair<int, int>>& linecols)
{
	for (int i = 0; i < tokens.size(); i++)
	{
		os << "Line " << linecols[i].first;
		os << ", Column " << linecols[i].second;
		os << ": " << tokens[i] << std::endl;
	}
}

int main(int argc, char* argv[])
{	
	string line = argv[1];
	vector<string> tokens;
	vector<string> maintokens;
	vector<pair<int, int>> linecols;

	std::ifstream file;
	file.open("text.txt");
	
	if (!file.eof())
	{
		while (getline(file, line))
		{
			LineToTokens(line, tokens);
			for (auto i : tokens)
			{
				maintokens.push_back(i);
			}
			ReadLine(cin, tokens, linecols);
			tokens.clear();
		}
	}
	
	PrintTokens(std::cout, maintokens, linecols);
	
	file.close();
	return 0;
}