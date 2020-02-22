/*
 *  Problem : ghepcap.cpp
 *  Description : 
 *  Created by ngocjr7 on [2019-10-14 08:41]	
*/
 
#include <bits/stdc++.h>
 
using namespace std;
const long N = 100000 + 7;
const long INF = 1000000000 + 7;
const long MODULE = 1000000000 + 7;
typedef pair<int,int> ii;
 
int n;
long long a[N], b[N];
 
int main()
{
	// freopen("in.txt","r",stdin);
 
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
 
	for (int i = 0; i < n; i++)
		cin >> b[i];
 
	sort(a, a+n);
	sort(b, b+n);
 
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (a[i] - b[i])*(a[i] - b[i]);
 
	cout << ans;
 
	return 0;
}