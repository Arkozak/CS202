#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::fstream;

int main()
{
	fstream f;
	f.open("data.dat", std::ios::in | std::ios::binary);

	int x;
	double count = 0;
	long long sum = 0;

	while (!f.eof())
	{
		count++;
		f.read(reinterpret_cast<char*>(&x), sizeof(int));
		sum = sum + x;
	}

	if (f.eof())
	{
		count--;
	}

	int avg = sum / count;
	cout << "Number of ints in file: " << count << endl;
	cout << "Sum: " << sum << endl;
	cout << "Average: " << avg << endl;




	f.close();


	return 0;
}