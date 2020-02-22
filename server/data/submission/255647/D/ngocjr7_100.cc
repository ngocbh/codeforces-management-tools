/*
 *  Problem : digits.cpp
 *  Description : 
 *  Created by ngocjr7 on [2019-10-15 08:21]	
*/

#include <bits/stdc++.h>

using namespace std;
const long N = 100000 + 7;
const long INF = 1000000000 + 7;
const long MODULE = 1000000000 + 7;
typedef pair<int,int> ii;
typedef long long ll;

int n;
ll f[10][20], rp[10][20], rs[10][20], np[10][20], ns[10][20];


int check_f(int a,int b)
{
	int ret = 0;
	string s = "";
	for (int i = a; i <= b; i++)
		s += to_string(i);

	for (int i = 1; i < s.size(); i++)
		if ( s[i] == s[i-1] ) 
			++ret;
	return s.size() - ret;
}

ll calc_ns(int i,int n)
{
	ll &ret = ns[i][n];
	if (ret != 0) return ret;
	if (n <= 1) return n;

	for (int j = 0; j < 10; j++)
		ret += calc_ns(j,n-1);
	return ret;
}

ll calc_rs(int i,int n)
{
	ll &ret = rs[i][n];
	if ( ret  != 0 ) return  ret;
	if ( n <= 1 ) return 0;

	for (int j = 0; j < 10; j++)
		if ( i == j ) 
			ret += calc_rs(i, n-1) + calc_ns(i,n-1);
		else 
			ret += calc_rs(j, n-1);
	return ret;
}

ll calc_rp(int i,int n)
{
	ll &ret = rp[i][n];
	if (ret != 0) return ret;
	if (n == 1) return 0;

	ret += calc_rs(i,n) + calc_ns(i,n-1);
	
	return ret;
}

ll calc_f(int i,int n);

ll prev_f(int i,int n)
{
	if ( n == 1 ) return i;
	if ( i == 1 ) 
		return calc_f(9,n-1);
	else 
		return calc_f(i-1,n);
}

ll calc_f(int i,int n)
{
	ll &ret = f[i][n];
	if (ret != 0) return ret;
	if (n == 1) return i;

	ret = 1ll*n*calc_ns(i,n) - calc_rp(i,n);
	ret += prev_f(i,n);
	return ret;
}

void init()
{
	memset(f, 0, sizeof f);
	memset(rp, 0, sizeof rp);
	memset(np, 0, sizeof np);
	memset(ns, 0, sizeof ns);
	calc_f(9,18);
}

string find_n(ll k)
{
	string ret = "";
	bool ok = true; 
	int n = 0;
	for (int j = 1; j <= 18; j++) {
		for (int i = 1; i < 10; i++) {
			if ( prev_f(i,j) <= k and k <= calc_f(i,j) ) {
				ret = (char)(i + '0');
				k -= prev_f(i,j);
				ok = false;
				n = j;
				break;
			}
		}
		if ( !ok ) break;
	}

	int dup = 0, m = 1;
	int first = ret[0] - '0';
	int last = first;

	while ( k > 0 ) {
		for (int i = 0; i < 10; i++) {
			ll cnt = 1ll*(n-dup)*calc_ns(i,n-m) - calc_rs(i,n-m) - 1ll*(last==i)*calc_ns(i,n-m);
			
			if ( n-m == 1 && i == first )
				cnt -= 1;
			else 
				cnt -= calc_ns(first,n-m-1);

			if ( n-m == 1 && i == first && k - cnt == 1 )
				cnt += 1;

			if ( k - cnt >= 0 ) {
				k -= cnt;
			} else {
				ret += (char)(i + '0');
				last = i;
				if (ret[m] == ret[m-1])
					++dup;
				++m;
				break;
			}
			if ( k <= 0 ) {
				ret += (char)(i + '0');
				break;
			}
		}
	}
	return ret;
}

int main()
{
	// freopen("in.txt","r",stdin);

	ll k;
	cin >> k;
	init();
	string ans = find_n(k);
	cout << ans;
	return 0;
}
