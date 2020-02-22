#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main()
{
	long long a = 1, s = 1;
	long long n;
	cin >> n;
	for(long long i = 1; i < n; i++)
	{
		long long ta = a, ts = s;
		a = (2 * ts + ta) % MOD;
		s = (3 * ts + ta) % MOD;
	}
	cout << s << endl;
}
