/*
 *  Problem : xaulap.cpp
 *  Description : 
 *  Created by ngocjr7 on [2019-10-14 00:00]	
*/

#include <bits/stdc++.h>

using namespace std;
const long N = 100000 + 7;
const long INF = 1000000000 + 7;
const long MODULE = 1000000000 + 7;
typedef pair<int,int> ii;

string s;

int main()
{
	//freopen("in.txt","r",stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	getline(cin,s);

	string ret = "";
	ret += s[0];

	for (int i = 1; i < s.size(); i++)
		if ( s[i] != s[i-1] ) 
			ret += s[i];

	cout << ret;

	return 0;
}
