#include<iostream>
#define MAX 100
using namespace std;
int main()
{
	int m;
	cin >> m;
	int A[MAX],B[MAX];
	for (int i = 0; i < 2 * m; i++)
	{
		cin >> A[i];
	}
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> B[i];
	}
	cout << "-1";
	return 0;
}