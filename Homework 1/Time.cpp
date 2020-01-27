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
	
	Time t;
	int x;

	t.begin();

	std::cin >> x;

	t.finish();

	t.begin();

	std::cin >> x;

	t.finish();
}