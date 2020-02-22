#include<bits\stdc++.h>
using namespace std;

int X[20001],Y[20001],C[20001];
long sochuot=0;
int xre=0;
int yre=0;
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
void Rat(int n,int d)
{
	for(int x=0;x<100;x++)
		for(int y=0;y<100;y++)
		{
			int temp=0;
			for(int i=0;i<n;i++)
				if(max( fabs(X[i]-x),fabs(Y[i]-y))<=d) temp+=C[i];
			if(temp>sochuot) 
			{
			xre=x;
			yre=y;
			sochuot=temp;
			}
		}
}
int main()
{
	int n,d;
	cin>>d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>X[i];
		cin>>Y[i];
		cin>>C[i];
	}
	Rat(n,d);
	printf("%d %d %d ",xre,yre,sochuot);
	return 0;
}