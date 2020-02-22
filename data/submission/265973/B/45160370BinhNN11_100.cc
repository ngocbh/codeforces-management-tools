#include<bits/stdc++.h>

using namespace std;

int d;
int n;
int M[20000][3];

void input()
{
	ios_base::sync_with_stdio(false);
	cin >> d >> n;
	for (int i =0; i < n; i++)
	{
		cin >> M[i][0] >> M[i][1] >> M[i][2];
	}
}

int Rat(int x0, int y0)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if( max(abs(M[i][0] - x0),  abs(M[i][1] - y0)) <= d)
			count = count + M[i][2];
	}
	return count;
}
int main()
{
	input();
	int MAX = 0;
	int x0, y0;
	for(int i = 0; i <= 100; i++)
	{
		for(int j= 0; j <= 100; j++)
		{
			int count = Rat(i, j);
			if(count > MAX){
				MAX = count;
				x0 = i;
				y0 = j;
			}
		}
	}
	cout << x0 << " " << y0<<" "<< MAX;
}

