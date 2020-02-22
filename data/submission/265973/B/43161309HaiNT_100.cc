//#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int d,n;
int x[10000], y[10000], c[10000];
int timmax(int a, int b)
{
	if (a<0) a = -a;
	if (b<0) b = -b;
	if (a > b) return a;
	else return b;
}
int main()
{
//	freopen("input.txt", "r", stdin);
	cin >> d >> n;
	int minx = 100000, miny = 10000,maxx=-1,maxy=-1;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> c[i];
		if (minx>x[i]) minx = x[i];
		if (maxx < x[i])maxx = x[i];
		if (miny>y[i]) miny = y[i];
		if (maxy < y[i])maxy = y[i];
	}
	int x0, y0;
	int kq = 0;
	//cout << minx << " " << miny << endl;
	//cout << maxx << " " << maxy << endl;
	for (int i = minx; i <= maxx; i++)
	{
		for (int j = miny; j <=maxy ; j++)
		{
			//cout << i << " " << j<< endl;
			int s = 0;
			for (int t = 0; t < n; t++)
			{
				if (timmax(x[t] - i, y[t] - j) <= d) s += c[t];
			}
			if (s>kq)
			{
				kq = s;
				x0 = i;
				y0 = j;
			}
			//cout << "kq=" << kq << endl;
		}
	}
	cout << x0 << " " << y0<<" " << kq <<endl;
	return 0;
}
