#include "jumpsuits.hpp"

int main()
{
	string suit;
	cout << "You are shopping jumpsuits." << endl;
	Jumpsuits jump;

	cout << "Which color would you like jumpsuit 1 to be? ";
	cin >> suit;
	jump.suit1add(suit);

	cout << "Which color would you like jumpsuit 2 to be? ";
	cin >> suit;
	jump.suit2add(suit);

	cout << "Which color would you like jumpsuit 3 to be? ";
	cin >> suit;
	jump.suit3add(suit);

	cout << jump;
}