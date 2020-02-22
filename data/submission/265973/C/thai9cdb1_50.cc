#include <iostream>
using namespace std;
int n,m;

long long int a[1000];

int main()
{
	int n;
	cin >> n;
	
	a[1] = 1;
	a[2] = 4;
	for (int i = 3; i <= n; i++) {
		a[i] = 4 * a[i-1] -a[i-2];
		a[i] %= 1000000007;

	}
	cout << a[n];
	
	return 0;
}