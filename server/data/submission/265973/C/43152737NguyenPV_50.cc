#include <iostream>
#include <math.h>
using namespace std;
int q = 1000000000+7;
int n;
int addmod(int a, int b, int P)
{
	a = a % P;
	b = b % P;
	int tmp = P - a;
	if(tmp > b)
	{
		return (a+b);
	}
	return b - tmp;
}
void solve()
{
	unsigned long long T[n];
	T[0] = 1;
	T[1] = 4;
	for(int i = 2; i < n; i++)
	{
		//T[i] = 4*T[i-1] - T[i-2];
		unsigned long long temp = addmod(T[i-1], T[i-1], q);
		T[i] = addmod(temp, temp, q);
		T[i] -= T[i-2];
	}
	cout<<T[n-1]%q;
}
int main()
{
	cin>>n;
	solve();
	return 0;
}