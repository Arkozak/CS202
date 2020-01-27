#include <iostream>
using std::cout;
#include <chrono>
using std::chrono::system_clock;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
#include <random>
#include <vector>


class Time
{
public:
	Time()
	{
		begin();
	}
	void begin()
	{
		start = system_clock::now();
	}
	void finish()
	{
		end = system_clock::now();
		cout << duration_cast<fsec>(end - start).count() << "sec\n";
		cout << duration_cast<fms>((end - start)*1000).count() << "ms\n";
	}
private:
	system_clock::time_point start;
	system_clock::time_point end;
	typedef std::chrono::duration<double> fsec;
	typedef std::chrono::duration<double> fms;
};

int main()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> num(1, 1000000);
	int x = num(rng);
	cout << "The random number for searching is " << x << std::endl;;

	std::vector<int> fill;
	for (int i = 0; i < 1000000; i++)
	{
		fill.push_back(i);
	}



}