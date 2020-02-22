<<<<<<< Updated upstream
//#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, k;
int a[10002];
int main()
{
//	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int s = 0;
	int kq = 0;
	for (int i = 0; i < n; i++)
	{
		s = 0;
		for (int j = i; j < n; j++)
		{
			s += a[j];
			if (s%k == 0) kq++;
		}
	}
	cout << kq << endl;
	return 0;
=======
//#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, k;
int a[10002];
int main()
{
//	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int s = 0;
	int kq = 0;
	for (int i = 0; i < n; i++)
	{
		s = 0;
		for (int j = i; j < n; j++)
		{
			s += a[j];
			if (s%k == 0) kq++;
		}
	}
	cout << kq << endl;
	return 0;
>>>>>>> Stashed changes
}