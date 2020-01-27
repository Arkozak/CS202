#include <iostream>
using std::cout;
using std::endl;
#include <chrono>
using std::chrono::system_clock;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;
#include <algorithm>


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
		cout << duration_cast<fms>((end - start) * 1000).count() << "ms\n";
	}
private:
	system_clock::time_point start;
	system_clock::time_point end;
	typedef std::chrono::duration<double> fsec;
	typedef std::chrono::duration<double> fms;
};


void add2vec(vector<string>& vec, string book)
{
	ifstream fin(book);

	//Can it read file?
	if (!fin)
	{
		cout << "Can't open file." << endl;
	}
	else
	{
		bool read = true;
		while (read)
		{
			string line;
			getline(fin, line);
			vec.push_back(line);

			//eof checking
			if (!fin)
			{
				if (fin.eof())
				{
					read = false;
				}
				else
				{
					read = true;
				}
			}
		}
	}
}


int main()
{

	cout << "Testing Vectors";

	//Filling vector
	vector<string> book1;
	vector<string> book2;
	vector<string> book3;
	vector<string> book4;
	vector<string> book5;

	cout << "The program is reading: Mrs Whittelsey's Magazine for Mothers and Daughters, Book Of Mormon, Hints For Lovers, The Kama Sutra, and Irish Fairy Tales." << endl;
	Time t;
	add2vec(book1, "Mrs_Whittelsey's_Magazine_for_Mothers_and_Daughters.txt");
	cout << "Added Mrs Whittelsey's Magazine for Mothers and Daughters to Vector." << endl;
	add2vec(book2, "Book_Of_Mormon.txt");
	cout << "Added Book Of Mormon to Vector." << endl;
	add2vec(book3, "Hints_For_Lovers.txt");
	cout << "Added Hints For Lovers to Vector." << endl;
	add2vec(book4, "Kama_Sutra.txt");
	cout << "Added The Kama Sutra to Vector." << endl;
	add2vec(book5, "Irish_Fairy_Tales.txt");
	cout << "Added Irish Fairy Tales to Vector." << endl;
	t.finish();

	cout << "Sorting vector of books." << endl;
	t.begin();
	std::sort(book1.begin(), book1.end());
	std::sort(book2.begin(), book2.end());
	std::sort(book3.begin(), book3.end());
	std::sort(book4.begin(), book4.end());
	std::sort(book5.begin(), book5.end());
	cout << "Sorted." << endl;
	t.finish();

	cout << "Searching for a random string in the vector." << endl;
	string random = "Random string";
	t.begin();
	if (std::find(book1.begin(), book1.end(), random) != book1.end())
	{
		cout << "String found!" << endl;
	}
	else
	{
		cout << "String not found." << endl;
	}
	if (std::find(book2.begin(), book2.end(), random) != book2.end())
	{
		cout << "String found!" << endl;
	}
	else
	{
		cout << "String not found." << endl;
	}
	if (std::find(book3.begin(), book3.end(), random) != book3.end())
	{
		cout << "String found!" << endl;
	}
	else
	{
		cout << "String not found." << endl;
	}
	if (std::find(book4.begin(), book4.end(), random) != book4.end())
	{
		cout << "String found!" << endl;
	}
	else
	{
		cout << "String not found." << endl;
	}
	if (std::find(book5.begin(), book5.end(), random) != book5.end())
	{
		cout << "String found!" << endl;
	}
	else
	{
		cout << "String not found." << endl;
	}
	t.finish();





	return 0;
}