//#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n;
int b[1000000], e[1000000];
int r[1000000]; // r[v] is rank of set v
int p[1000000]; // p[v] is parent of v
int m = 0;
int x[1000000];
int ans;
void link(int x, int y)
{
	if (r[x] > r[y])
	{
		p[y] = x; // x is parent of y
		r[x] = r[x] + 1;
	}
	else
	{
		p[x] = y;
		if (r[x] == r[y]) r[y] = r[y] + 1; // tang rank y len 1
	}
}
// make set of x
void makeSet(int x)
{
	p[x] = x;
	r[x] = 0;
}
// find set
int findSet(int x)
{
	if (x != p[x])
		p[x] = findSet(p[x]);
	return p[x];
}
// check if set edges (b[X[1]], e[X[1]]), (b[X[2]], e[X[2]]), ... (b[X[val]], e[X[val]])
// induces a cycle
int check(int val, int k)
{
	for (int i = 1; i <= n; i++) makeSet(i);
	for (int j = 1; j < k; j++)
	{
		int u = b[x[j]];
		int v = e[x[j]];
		int ru = findSet(u);
		int rv = findSet(v);
		if (ru == rv) return 0; // ru == rv tuc la tao thanh cycle
		link(ru, rv); // link ru with rv
	}
	if (findSet(b[val]) == findSet(e[val])) return 0;
	return 1;

}

void solution()
{
	ans++;
	/*for (int i = 1; i <= n - 1; i++)
		cout << "(" << b[x[i]] << "," << e[x[i]] << ")";
	cout << endl;*/
}

void TRY(int k)
{
	for (int v = x[k - 1] + 1; v <= m; v++)
	{
		int ok = check(v, k);
		if (ok)
		{
			x[k] = v;
			if (k == n - 1)
			{
				solution();
			}
			else
			{
				TRY(k + 1);
			}

		}
	}
}

void solve()
{
	ans = 0;
	x[0] = 0;
	TRY(1);
}


int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <=2*n ; i++)
	{
		if (i % 2 == 1 && i != 2*n -1)
		{
			m++;
			b[m] = i;
			e[m] = i + 1;
			m++;
			b[m] = i;
			e[m] = i + 2;
		}
		if (i % 2 == 0 && i != 2 * n)
		{
			m++;
			b[m] = i;
			e[m] = i + 2;
		}
		if (i == 2 * n - 1)
		{
			m++;
			b[m] = i;
			e[m] = i + 1;
		}

	}
	n = 2 * n;
	solve();
	cout << ans << endl;
	//for (int i = 1; i <= m; i++)
	//{
	//	cout << b[i] << e[i] << endl;
	//}
	//cout << m << endl;
	return 0;
}