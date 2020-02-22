#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int main() 
{
	//ios::sync_with_stdio(false);
	//ifstream cin("input.txt");
	int n, k;
	cin >> n >> k;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % k == 0)
		{
			dem++;
		}
	}
	int s = 0;
	for (int i = 1; i < n; i++)
	{
		s = a[i];
		for (int j = i-1; j >= 0; j--)
		{
			s += a[j];
			if (s % k == 0) dem++;
		}
	}
	cout << dem << endl;
	return 0;


}