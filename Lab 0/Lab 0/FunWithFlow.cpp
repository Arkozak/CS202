#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;

void readback(vector<string> suitcolors)
{
	cout << "The colors you purchased were: \n";
	for (auto i : suitcolors)
	{
		cout << i << endl;
	}
}

int main()
{
	int x = 0;
	int y = 0;
	vector<string> suitcolors ;
	string suit;
	string answer = "Yes";

	cout << "You are shopping jumpsuits, how many would you like to buy? " << endl;
	cin >> y;
	
	while (x == 0)
	{
		for (int i = 0; i < y; i++)
		{
			cout << "Which color would you like jumpsuit " << i + 1 << " to be? ";
			cin >> suit;
			suitcolors.push_back(suit);
		}

		if (suitcolors.size() == y)
		{
			x = 1;
		}
	}
	readback(suitcolors);
}