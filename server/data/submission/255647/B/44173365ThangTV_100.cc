#include<iostream>
using namespace std;
int main() {
	int a[1000000], n, i, j, maxd, maxl, tt,l,x,MD=0,MTL=0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	//1 lend,2 xuongd
	i = 0;
	l = 0;
	while (i < (n - 1))
	{
		while (i<(n-1) && a[i] == a[i + 1]) i++;
		x = 0;
		while (i<(n-1) &&a[i] > a[i + 1])
		{
			x++;
			i++;
		}
		if (l > x) maxd = x;
		else maxd = l;
		l = 0;
		while (i<(n-1) &&a[i] < a[i + 1])
		{
			l++;
			i++;
		}
		if (l > x) maxl = x;
		else maxl = l;
		if (MD < maxd) MD = maxd;
		if (MTL < maxl) MTL = maxl;
	}
	cout << MD << " " << MTL;
	//system("pause");
}