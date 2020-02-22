#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 101LL

int main()
{
	long long d, n;
	cin >> d >> n;
	vector<vector<long long>> mat(MAXSIZE, vector<long long>(MAXSIZE));
	for(long long i = 0; i < n; i++)
	{
		long long x, y, c;
		cin >> x >> y >> c;
		mat[x][y] = c;
	}
	long long res = 0;
	long long rx = -1, ry = -1;
	for(long long i = 0; i <= 100; i++)
	{
		for(long long j = 0; j <= 100; j++)
		{
			long long count = 0;
			for(long long x = max(0LL, i - d); x <= min(MAXSIZE - 1, i + d); x++)
			{
				for(long long y = max(0LL, j - d); y <= min(MAXSIZE - 1, j + d); y++) count += mat[x][y];
			}
			if(count > res)
			{
				res = count;
				rx = i;
				ry = j;
			}
		}
	}
	cout << rx << " " << ry << " " << res << endl;
}
