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
	void finish()
	{
		end = system_clock::now();
		cout << duration_cast<seconds>(end - start).count() << "sec\n";
		cout << duration_cast<milliseconds>(end - start).count() << "ms\n";
	}
private:
	system_clock::time_point start;
	system_clock::time_point end;
};

