<<<<<<< Updated upstream
#include<iostream>
#include<math.h>
using namespace std;
int gtln(int p, int l)
{
	if (p < l)
		return l;
	else
		return p;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int d;
	int a[101][101];
	int n;
	cin >> d;
	cin >> n;
	int c[100000];
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int x, y,c;
		cin >> x >> y>>c;
		a[x][y] = c;
	}
	int result = 0,vtx=99,vty=99;
	for (int i = 100; i >= 0; i--)
	{
		for (int j = 100; j>=0; j--)
		{
			int sum = 0;
			for (int t = 0; t < 101; t++)
			{
				for (int k = 0; k < 101; k++)
				{
					if (a[t][k] != 0 && gtln(abs(i - t), abs(j - k)) <= d)
					{
						sum += a[t][k];
					}
				}
			}
			if (sum >= result)
			{
				result = sum;
				vtx = i;
				vty = j;
			}
			
		}
	}
	cout << vtx << " " << vty << " " << result;
}

=======
#include<iostream>
#include<math.h>
using namespace std;
int gtln(int p, int l)
{
	if (p < l)
		return l;
	else
		return p;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int d;
	int a[101][101];
	int n;
	cin >> d;
	cin >> n;
	int c[100000];
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int x, y,c;
		cin >> x >> y>>c;
		a[x][y] = c;
	}
	int result = 0,vtx=99,vty=99;
	for (int i = 100; i >= 0; i--)
	{
		for (int j = 100; j>=0; j--)
		{
			int sum = 0;
			for (int t = 0; t < 101; t++)
			{
				for (int k = 0; k < 101; k++)
				{
					if (a[t][k] != 0 && gtln(abs(i - t), abs(j - k)) <= d)
					{
						sum += a[t][k];
					}
				}
			}
			if (sum >= result)
			{
				result = sum;
				vtx = i;
				vty = j;
			}
			
		}
	}
	cout << vtx << " " << vty << " " << result;
}

>>>>>>> Stashed changes
