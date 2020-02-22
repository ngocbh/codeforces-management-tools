#include<bits\stdc++.h>
using namespace std;

int X[20001],Y[20001],AC[20001];
long S=0;
int xp=0;
int yp=0;
void Rat(int n,int d)
{
	for(int x=0;x<100;x++)
		for(int y=0;y<100;y++)
		{
			int temp=0;
			for(int i=0;i<n;i++)
				if(max( fabs(X[i]-x),fabs(Y[i]-y))<=d) temp+=AC[i];
			if(temp>S) 
			{
			xp=x;
			yp=y;
			S=temp;
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
		cin>>AC[i];
	}
	Rat(n,d);
    cout<<xp<< " "<< yp<<" "<< S;

	return 0;
}