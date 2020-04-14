#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class Base
{
public:
	Base() {
		cout << "Constructing Base object with initial value of:  " << initial << endl;
	}

	Base(int _initial) : initial (_initial)
	{
		cout << "Constructing Base object with initial value of:" << initial << endl;
	}

	~Base() {
		cout << "Destructing  Base object with value of:" << initial << endl;
	}

private:
	int initial = 20;
};

int main()
{
	Base a; 
	cout << endl;

	Base b(2); 
	cout << endl;

	return 0;
}