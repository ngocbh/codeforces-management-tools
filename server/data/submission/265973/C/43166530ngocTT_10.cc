#include<fstream>
#include<iostream>
using namespace std;

const int P = 1000000007;
int Spanning(int x)
{
	int rs = 0;

	rs = x * x;
	return rs;
}

int main()
{
	int n;
	cin >> n;
	int s = Spanning(n);
	cout << s % P;
	return 0;
}
