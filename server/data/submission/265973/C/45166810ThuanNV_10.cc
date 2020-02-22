#include<iostream>
using namespace std;
int n;
int tinh(int a)
{
	if (a == 1)
		return 1;
	else if (a == 2)
		return 4;
	else
	{
		return (3 * n + 1) * tinh(a - 1) - n * tinh(a - 2);
	}

}
int main()
{
	
	cin >> n;
	cout <<tinh(n);
}