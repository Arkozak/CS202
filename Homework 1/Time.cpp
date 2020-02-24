#include <iostream>
using std::cout;
using std::endl;
#include <chrono>
using std::chrono::system_clock;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
#include <random>
#include <vector>

//test
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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 1000000);
	std::vector<int> random = { dis(gen) };
	int x = dis(gen);
	cout << "The random number for searching is " << x << endl;;

	
	std::vector<int> dataset;
	for (int i = 0; i < 1000000; i++)
	{
		dataset.push_back(i);
	}

	//Shuffling
	cout << "Shuffling dataset took: " << endl;
	Time t;
	std::shuffle(dataset.begin(), dataset.end(), gen);
	t.finish();

	//Sorting
	cout << "Sorting dataset took: " << endl;
	t.begin();
	std::sort(dataset.begin(), dataset.end());
	t.finish();

	//Standard search
	cout << "Search took: " << endl;
	t.begin();
	std::search(dataset.begin(), dataset.end(), random.begin(),
		random.end());
	t.finish();

	//Binary search
	cout << "Binary Search took: " << endl;
	t.begin();
	std::binary_search(dataset.begin(), dataset.end(), random[0]);
	t.finish();

	


}