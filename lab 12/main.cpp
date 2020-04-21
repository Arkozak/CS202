#include <iostream>
using std::cout;
using std::endl;
#include <string>

// [X] Write Base class with two methods (one virtual)
// [X] Write a Derived class with two methods (one virtual)
// [X] Test base class pointer to base class object
// [X] Test base class pointer to derived class object
// [X] Test derived class pointer to derived class object
// [X] Test base class reference to base class object
// [X] Test base class reference to derived object
// [X] Test derived class reference to derived class object

class Base {
public:
	Base() 
	{ 
		cout << "Base Class Constructor" << endl; 
	}
	virtual ~Base() 
	{ 
		cout << "Base Class Destructor" << endl;
	}

	void fNonVirt() 
	{
		cout << "Base Non-Virtual Function" << endl;
	}
	virtual void fVirt() 
	{ 
		cout << "Base Virtual Function" << endl; 
	}
};

class Derived : public Base {
public:
	Derived() 
	{ 
		cout << "Derived Class Constructor" << endl;
	}
	~Derived() 
	{ 
		cout << "Derived Class Destructor" << endl;
	}

	void fNonVirt()
	{ 
		cout << "Derived Non-Virtual Function" << endl;
	}
	void fVirt() override 
	{ 
		cout << "Derived Virtual Function" << endl;
	}
};

void testBasePnt() {
	Base b;
	{
		Base* testbp = &b;
		testbp->fNonVirt();
		testbp->fVirt();
	}

	Derived d;
	{ 
		Base* testbp = &d;
		testbp->fNonVirt();
		testbp->fVirt();
	}

	Derived* testdp = &d;
	testdp->fNonVirt();
	testdp->fVirt();
}

void testBaseRef() {
	Base b;
	{ 
		Base& testbr = b;
		testbr.fNonVirt();
		testbr.fVirt();
	}

	Derived d;
	{
	Base& testbr = d;
	testbr.fNonVirt();
	testbr.fVirt();
	}

	Derived& testdr = d;
	testdr.fNonVirt();
	testdr.fVirt();
}



int main(int argc, char** argv)
{
	Base b; 
	b.fNonVirt();
	b.fVirt(); 
	cout << "\n\n\n";

	Derived d; 
	d.fNonVirt(); 
	d.fVirt(); 
	cout << "\n\n\n";
	
	testBasePnt();
	cout << "\n\n\n";

	testBaseRef();
	cout << "\n\n\n";

	return 0;
}