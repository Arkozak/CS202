#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
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
		cout << "It took: " << duration_cast<fsec>(end - start).count() << "sec\n";
	}
private:
	system_clock::time_point start;
	system_clock::time_point end;
	typedef std::chrono::duration<double> fsec;
};

bool isprime(int boop, vector<int> boops)
{
	for (int i = 0; i < boops.size(); i++)
	{
		if ((boop % boops[i]) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<int> boops = { 2 };
	int boopcount = 0;
	int howmany;
	int j=4;
	cout << "What prime: ";
	cin >> howmany;
	Time t;
	for (int boop = 3; boop < j; boop += 2)
	{
		if (isprime(boop , boops) == 1)
		{
			boops.push_back(boop);
			boopcount++;
		}
		if (boopcount == howmany - 1)
		{
			cout << boop << endl;
			t.finish();
			return 0;
		}
		j += 2;
	}
}