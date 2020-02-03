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

