#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<long long> a;
	long long n, k;
	cin >> n >> k;
	vector<long long> s;
	s.push_back(0);
	for(long long i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		a.push_back(temp);
		s.push_back(s[s.size() - 1] + temp);
	}
	long long r = 0;
	for(long long i = 0; i < n + 1; i++)
	{
		for(long long j = i + 1; j < n + 1; j++)
		{
			if((s[j] - s[i]) % k == 0) r++;
		}
	}
	cout << r << endl;
}
