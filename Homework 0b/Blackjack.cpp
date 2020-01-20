#include <iostream>
using std::cin;
using std::cout;
#include <map>
using std::map;
#include <string>
using std::string;
#include <random>;
#include <vector>;
using std::vector;

int main()
{
	//Random Number Generator
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> card(1, 52);

	//Creating Deck
	map<int,int> deck;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			deck[j + (13 * i)] = j;
		}
		for (int k = 10; k < 14; k++)
		{
			deck[k + (13 * i)] = 10;
		}
	}

	//Creating hands and a drawn pile
	int hand = 0;
	int dealer = 0;
	int x;
	int boop = 4;
	string str;
	vector<int> drawn;

	//Drawing cards
	for (int i = 0; i < 52; i++)
	{
		x = card(rng);
		if (std::find(drawn.begin(), drawn.end(), x) != drawn.end())
		{
			i--;
		}
		else
		{
			drawn.push_back(x);
		}
	}

	dealer = deck[drawn[0]] + deck[drawn[2]];
	hand = deck[drawn[1]] + deck[drawn[3]];

	cout << "You have " << hand << " points.\n";
	cout << "The dealer has " << deck[drawn[2]] << " points face up.\n";
	
	while (boop != 0)
	{
		cout << "Would you like to hit? (Yes/No)";
		cin >> str;
		if (str == "Yes")
		{
			hand = hand + deck[drawn[boop]];
			boop++;
			
			if (hand > 21)
			{
				cout << "You bust! Congrats!";
				return 0;
			}
			else
			{
				cout << "You have " << hand << " points.\n";
			}
		}
		if (str == "No")
		{
			break;
		}
	}

	while (dealer < 17)
	{
		dealer = dealer + deck[drawn[boop]];
		boop++;
		if (dealer > 21)
		{
			cout << "The dealer bust! You win!";
			return 0;
		}
	}

	if (hand <= 21)
	{
		cout << "The dealer has " << dealer << " points, you have " << hand << " points.\n";
		if (hand > dealer)
		{
			cout << "You win!";
		}
		else
		{
			cout << "You lose! Congrats!";
		}
	}
	
	return 0;
}