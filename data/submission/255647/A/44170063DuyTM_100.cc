#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	string res;
	getline(cin, s);
	res += s[0];
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] != s[i - 1]) res += s[i];
	}
	cout << res << endl;
}
