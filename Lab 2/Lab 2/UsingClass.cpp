
#include "ClassStuff.hpp"

int main()
{
	string suit;
	Jumpsuits defConst;
	int y = 0;
	cout << "You are shopping jumpsuits, how many would you like to buy? " << endl;
	cin >> y;
	Jumpsuits jump(y);

	for (int i = 0; i < jump.getX(); i++)
	{
		cout << "Which color would you like jumpsuit " << i + 1 << " to be? ";
		cin >> suit;
		jump.addColor(suit);
	}

	jump.readback();


}