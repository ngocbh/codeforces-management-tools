#include<iostream>
using namespace std;
int main()
{
	int a[10000];
	int n,k;
	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int tong;
	int dem=0;
	for (int i=0;i<n-1;i++)
	{
		tong = 0;
		for (int j=i;j<n;j++)
		{
			tong+=a[j];
			if (tong % k ==0) dem ++;
		}
	}
	cout<<dem;
	return 0;
}

