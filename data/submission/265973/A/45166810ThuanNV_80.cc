#include<iostream>
using namespace std;
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	int a[100000];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
	
		for (int j = 1; j < n - i+1; j++)
		{
			int sum = 0;
			for (int t = 0; t < j; t++)
			{
				sum += a[i+t];
			}
			if (sum % k == 0)
			{
				dem++;
			}
		}
	}
	cout << dem;
}