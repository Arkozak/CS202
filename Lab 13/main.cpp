#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

template <typename WrapType>
class Wrapper {
public:
	Wrapper(const WrapType& obj) : obj(obj) {}

private:
	WrapType obj;
	template <typename Temp>
	friend std::ostream& operator<<(std::ostream& os, const Wrapper<Temp>& w);
};

template <typename Temp>
std::ostream& operator<<(std::ostream& os, const Wrapper<Temp>& wrapper) 
{
	os << wrapper.obj;
	return os;
}

int main()
{
	Wrapper<int> w{ 2 };
	Wrapper<string> s{ "Hello, World" };

	cout << w << " " << s << endl;

	return 0;
}