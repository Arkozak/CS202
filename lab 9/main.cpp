#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
#include <string>
#include <sstream>

// [X] Static local variable
// [X] Static global variable
// [X] Static member variable
// [X] Static member function

static int test_static_count = 0;

class TestStatic
{
public:
	TestStatic() :
		instanceNum_(test_static_count) {
		cout << __FUNCTION__ << " " << instanceNum_ << " initialized." << endl;
		test_static_count++;

		std::ostringstream ostr;
		ostr << "TestStatic" << instanceNum_;
		_className = ostr.str();
	}

	~TestStatic()
	{
		cout << __FUNCTION__ << " " << instanceNum_ << " destroyed." << endl;
	}

	void printClassName()
	{
		cout << _className << endl;
	}

	static void writeClassName()
	{
		cout << "Static " << _className << endl;
	}

	static void writeClassName(const TestStatic& ts)
	{
		cout << "Static instance: " << ts.instanceNum_ << endl;

	}

private:
	int instanceNum_;
	static std::string _className;
};

std::string TestStatic::_className{ "test" };

namespace
{
	TestStatic ts1;
	TestStatic ts2;
}

void foo_static()
{
	static int count = 0;
	static TestStatic ts;
	if (!count)
	{
		cout << __FUNCTION__ << " is not initialized" << endl;
		count = 1;
	}
	else
	{
		cout << __FUNCTION__ << " called " << count << " times" << endl;
		count++;
	}
	ts.printClassName();
}

int main(int argc, char** argv)
{
	cout << "Starting main" << endl;

	ts1.printClassName();
	ts2.printClassName();

	foo_static();
	foo_static();
	foo_static();

	ts1.printClassName();
	TestStatic::writeClassName(ts1);
	TestStatic::writeClassName(ts2);

	cout << "Leaving main" << endl;

	return 0;
}