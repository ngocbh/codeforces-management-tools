#include <iostream>
using namespace std;
#define MAX 10001
int a[MAX];
int n, k;
void solve()
{
	long long sum[MAX];
	long long q = 0;
	for(int i = 0; i < n; i++)
	{
		sum[i] = a[i];
		if(sum[i] % k == 0)
		{
			q++;
		}
		for(int j = i+1; j < n; j++)
		{
			sum[i] += a[j];
			if(sum[i] % k == 0)
			{
				q++;
			}
		}
	}
	cout<<q;
}
int main()
{
	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	solve();
}