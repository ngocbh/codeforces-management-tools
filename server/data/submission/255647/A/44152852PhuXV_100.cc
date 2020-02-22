#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string s1;
	int i = 0;
	int k = 0;
	while (i < s.length())
	{
		if (s[i] != s[i + 1])
		{
			s1 = s1 + char(s[i]);

		}
		i++;
	}
	cout << s1;
	//system("pause");
	return 0;
}