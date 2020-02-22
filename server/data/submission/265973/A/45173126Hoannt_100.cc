#include<iostream>
using namespace std;
int n, k;
int A[10001];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int cou = 0;
	for (int i = 0; i < n; i++)
	{
		int s = 0;
		for (int j = i; j < n; j++)
		{
			s += A[j];
			if (s % k == 0) cou++;
		}
	}
	cout << cou;
//	system("pause");
}