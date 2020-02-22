<<<<<<< Updated upstream
#include<fstream>
#include<iostream>
using namespace std;

int d, n;
int x[10000], y[10000], c[10000];
int mmax(int a, int b)
{
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a > b) return a;
	else return b;
}
int main()
{
	//ifstream cin("input.txt");
	cin >> d >> n;
	int min_x = 10000, min_y = 10000, max_x = -1, max_y = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> c[i];
		if (min_x > x[i]) min_x = x[i];
		if (max_x < x[i]) max_x = x[i];
		if (min_y > y[i]) min_y = y[i];
		if (max_y < y[i]) max_y = y[i];
	}
	int x0, y0;
	int kq = 0;

	for (int i = min_x; i <= max_x; i++)
	{
		for (int j = min_y; j <= max_y; j++)
		{

			int s = 0;
			for (int t = 0; t < n; t++)
			{
				if (mmax(x[t] - i, y[t] - j) <= d) s += c[t];
			}
			if (s > kq)
			{
				kq = s;
				x0 = i;
				y0 = j;
			}

		}
	}
	cout << x0 << " " << y0 << " " << kq << endl;
	return 0;
}
=======
#include<fstream>
#include<iostream>
using namespace std;

int d, n;
int x[10000], y[10000], c[10000];
int mmax(int a, int b)
{
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a > b) return a;
	else return b;
}
int main()
{
	//ifstream cin("input.txt");
	cin >> d >> n;
	int min_x = 10000, min_y = 10000, max_x = -1, max_y = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> c[i];
		if (min_x > x[i]) min_x = x[i];
		if (max_x < x[i]) max_x = x[i];
		if (min_y > y[i]) min_y = y[i];
		if (max_y < y[i]) max_y = y[i];
	}
	int x0, y0;
	int kq = 0;

	for (int i = min_x; i <= max_x; i++)
	{
		for (int j = min_y; j <= max_y; j++)
		{

			int s = 0;
			for (int t = 0; t < n; t++)
			{
				if (mmax(x[t] - i, y[t] - j) <= d) s += c[t];
			}
			if (s > kq)
			{
				kq = s;
				x0 = i;
				y0 = j;
			}

		}
	}
	cout << x0 << " " << y0 << " " << kq << endl;
	return 0;
}
>>>>>>> Stashed changes
