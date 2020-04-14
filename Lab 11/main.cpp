#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class Base
{
public:
	Base() 
	{
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

class Derived : public Base 
{
public:
	Derived(): Base(1980), movie("Original IT")
	{
		cout << "Constructing a Derived object with movie title: " << movie << endl;
	}

	Derived(int initial, const std::string& title): Base(initial), movie(title)
	{
		cout << "Constructing a Derived object with movie title: " << movie << endl;
	}

	~Derived() 
	{
		cout << "Destructing a Derived object with movie title: " << movie << endl;
	}

private:
	string movie;
};

int main()
{
	Base a; 
	cout << endl;

	Base b(2); 
	cout << endl;

	Derived c;
	cout << endl;

	Derived d (2017, "New IT"); 
	cout << endl;

	return 0;
}