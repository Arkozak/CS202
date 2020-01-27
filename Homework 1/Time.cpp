#include <iostream>
using std::cout;
#include <chrono>
using std::chrono::system_clock;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::duration_cast;


class Time
{
public:
	void begin()
	{
		start = system_clock::now();
	}
	
private:
	system_clock::time_point start;
};

