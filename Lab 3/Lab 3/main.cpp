#include <memory>
#include "ClassStuff.hpp"

int main()
{
	cout << "Creating raw pointer.\n";
	Jumpsuits* ptr = new Jumpsuits();
	

	string color1 = "purple";
	string color2 = "orange";
	string color3 = "maroon";
	string suit;
	int y = 0;
	cout << "You are shopping jumpsuits, how many would you like to buy? " << endl;
	cin >> y;


	cout << "\nCreating unique pointer with a parameter (number of suits).\n";
	std::unique_ptr<Jumpsuits> jump(new Jumpsuits(y));
	

	for (int i = 0; i < jump -> getX(); i++)
	{
		cout << "Which color would you like jumpsuit " << i + 1 << " to be? ";
		cin >> suit;
		jump->addColor(suit);
	}


	cout << "\nTransfering ownership to a new unique function.\n";
	std::unique_ptr<Jumpsuits> jump2 = move(jump);


	cout << "Calling memeber function in the unique pointer.\n";
	jump2->readback();


	cout << "\nCreating a shared poointer with a parameter and creating another shared pointer to the same object.\n";
	std::shared_ptr<Jumpsuits> sharejump(new Jumpsuits(color1, color2, color3));
	std::shared_ptr<Jumpsuits> sharejump2(sharejump);
	

	cout << "\nCalling memeber function in the shared pointer.\n";
	sharejump2->readback();
}