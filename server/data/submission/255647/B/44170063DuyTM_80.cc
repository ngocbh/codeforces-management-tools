#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	long long n;
	cin >> n;
	vector<long long> a(n);
	for(long long i = 0; i < n; i++) cin >> a[i];
	long long res1 = 0, res2 = 0;
	if(n > 2)
	{
		long long i = 0;
		while(i < n - 2)
		{
			while((i < n - 1) && (a[i] == a[i + 1])) i++;
			long long i1 = i;
			while((i < n - 1) && (a[i] < a[i + 1])) i++;
			long long j1 = i;
			while((i < n - 1) && (a[i] > a[i + 1])) i++;
			long long k1 = i;
			long long height = min(j1 - i1, k1 - j1);
			#ifdef DEBUG
			cout << "1: " << i1 << " " << j1 << " " << k1 << " " << height << endl;
			#endif
			if((i1 < j1) && (j1 < k1)) res1 = max(res1, height);
		}
		i = 0;
		while(i < n - 2)
		{
			while((i < n - 1) && (a[i] == a[i + 1])) i++;
			long long i1 = i;
			while((i < n - 1) && (a[i] > a[i + 1])) i++;
			long long j1 = i;
			while((i < n - 1) && (a[i] < a[i + 1])) i++;
			long long k1 = i;
			long long depth = min(j1 - i1, k1 - j1);
			#ifdef DEBUG
			cout << "2: " << i1 << " " << j1 << " " << k1 << " " << depth << endl;
			#endif
			if((i1 < j1) && (j1 < k1)) res2 = max(res2, depth);
		}
	}
	cout << res1 << " " << res2 << endl;
}
