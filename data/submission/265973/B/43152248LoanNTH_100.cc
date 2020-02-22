<<<<<<< Updated upstream
#include <iostream>
using namespace std;
#define Nmax 20000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char** argv) {
	int d,n;
	int A[150][150];
	int x;
	int y;
	int s;
	int rat;
	int e,f,g,h;
	int x_max, y_max, rat_max=0;
//	for(int i=0; i<101; i++)
//	{
//		for(int j=0; j<101; j++)
//		{
//			A[i][j]=0;
//		}
//	}
	
	cin>>d>>n;
	for(int i=1; i<102; i++)
	{
		for(int j=0; j<102; j++)
		{
			A[i][j]=0;
		}
	}
	for(int k=0; k<n; k++)
	{
		cin>>x>>y>>s;
		A[x][y]=s;
	}
	for(int u=0; u<=101; u++)
	{
		for(int v=0; v<=101; v++)
		{
			rat=0;
			 e=0;f=0;g=0;h=0; //dieu kien bien
			if(u>=d)
				e=u-d;
			else e=0;
			if(v>=d)f=v-d;
			else f=0;
			if(u+d<=101)
				g=u+d;
			else g=101;
			if(v+d<=101)
				h=v+d;
			else h=101;
			for(int i=e; i<=g; i++)
			{
				for(int j=f; j<=h; j++)
				{
					rat=rat+A[i][j];
				}
			}
			if(rat>rat_max)
			{
				rat_max=rat;
				x_max=u;y_max=v;
			}
		}
	}
	cout<<x_max<<" "<<y_max<<" "<<rat_max;
	return 0;
=======
#include <iostream>
using namespace std;
#define Nmax 20000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char** argv) {
	int d,n;
	int A[150][150];
	int x;
	int y;
	int s;
	int rat;
	int e,f,g,h;
	int x_max, y_max, rat_max=0;
//	for(int i=0; i<101; i++)
//	{
//		for(int j=0; j<101; j++)
//		{
//			A[i][j]=0;
//		}
//	}
	
	cin>>d>>n;
	for(int i=1; i<102; i++)
	{
		for(int j=0; j<102; j++)
		{
			A[i][j]=0;
		}
	}
	for(int k=0; k<n; k++)
	{
		cin>>x>>y>>s;
		A[x][y]=s;
	}
	for(int u=0; u<=101; u++)
	{
		for(int v=0; v<=101; v++)
		{
			rat=0;
			 e=0;f=0;g=0;h=0; //dieu kien bien
			if(u>=d)
				e=u-d;
			else e=0;
			if(v>=d)f=v-d;
			else f=0;
			if(u+d<=101)
				g=u+d;
			else g=101;
			if(v+d<=101)
				h=v+d;
			else h=101;
			for(int i=e; i<=g; i++)
			{
				for(int j=f; j<=h; j++)
				{
					rat=rat+A[i][j];
				}
			}
			if(rat>rat_max)
			{
				rat_max=rat;
				x_max=u;y_max=v;
			}
		}
	}
	cout<<x_max<<" "<<y_max<<" "<<rat_max;
	return 0;
>>>>>>> Stashed changes
}