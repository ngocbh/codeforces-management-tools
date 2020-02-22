#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define MAX 20000
int d;
int n;
typedef pair<int, int> myPair;
vector<myPair> position;
vector<int> rat;

void input()
{
	cin>>d;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		int r;
		cin>>x>>y>>r;
		position.push_back(make_pair(x, y));
		rat.push_back(r);
	}
}
void solve()
{
	long long maxrat = 0;
	int xm = 0;
	int ym = 0;
	for(int x0 = 0; x0 <= 100; x0 ++)
	{
		for(int y0 = 0; y0 <= 100; y0 ++)
		{
			long long num = 0;
			for(int i = 0; i < n; i++)
			{
				pair<int, int> p = position[i];
				if(abs(p.first - x0) <= d)
				{
					if(abs(p.second - y0) <= d)
					{
						num += rat[i];
					}
				}
			}
			if(num > maxrat)
			{
				maxrat = num;
				xm = x0;
				ym = y0;
			}
		}
	}
	cout<<xm<<" "<<ym<<" "<<maxrat << endl;
}
int main()
{
	input();
	solve();
}