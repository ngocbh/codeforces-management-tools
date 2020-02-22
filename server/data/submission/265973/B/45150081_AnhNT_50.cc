#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
struct  mouse {
	long long x,y,w;
};

int main()
{
	long long d,n;
	struct mouse a[20005];
	cin>>d>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	long long maxDie=0;
	long long xmax = 0;
	long long ymax=0;
	long long die;
	for(long long i=1;i<101;i++)
	{
		for(long long j=1;j<101;j++)
		{
			die=0;
			for(long long k=0;k<n;k++)
			{
				if (max(abs(a[k].x - i), abs(a[k].y - j)) <=d) die+= a[k].w;
			}
		if (maxDie == die)
		{
			if (xmax < i)
			{
				xmax = i;
				ymax = j;
			}
			else if(xmax ==i && ymax<j)
			{
				xmax =i;
				ymax=j;
			}
		}
		if(maxDie<die)
		{
			maxDie=die;
			xmax=i;
			ymax=j;
		}
	}
	}
	cout<<xmax<<" "<<ymax<<" "<<maxDie;
	return 0;
}
