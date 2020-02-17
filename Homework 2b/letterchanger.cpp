#include <iostream>
#include <string>
using namespace std;

void to_lower(char* s)
{
	for (int i = 0; s[i]; ++i) 
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			s[i] = s[i] - ('A' - 'a');
		}
	}
}

int main()
{
	string word;				
	while (word != "quit")
	{
		cin >> word;
		char* s = &word[0];
		to_lower(s);
		cout << s << ' ';
	}
}