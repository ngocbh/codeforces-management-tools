<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	int d,n,i,j,a,b,c,h,k,max=0,sum=0;
	cin >> d >> n;
	int A[101][101]={0};
	for (i=0;i<n;i++)
		{
			cin >> a >> b >> c; A[a][b]=c;
		}
	for (i=d;i<=100-d;i++)
	{
		for (j=d;j<=100-d;j++)
		{	sum=0;
			for (h=i-d;h<=i+d;h++)
				for (k=j-d;k<=j+d;k++)
				sum+=A[h][k];
			if (sum>max) { max = sum; a=i;b=j;}
		}
	}
	cout << a << " " << b << " " << max;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	int d,n,i,j,a,b,c,h,k,max=0,sum=0;
	cin >> d >> n;
	int A[101][101]={0};
	for (i=0;i<n;i++)
		{
			cin >> a >> b >> c; A[a][b]=c;
		}
	for (i=d;i<=100-d;i++)
	{
		for (j=d;j<=100-d;j++)
		{	sum=0;
			for (h=i-d;h<=i+d;h++)
				for (k=j-d;k<=j+d;k++)
				sum+=A[h][k];
			if (sum>max) { max = sum; a=i;b=j;}
		}
	}
	cout << a << " " << b << " " << max;
}
>>>>>>> Stashed changes
