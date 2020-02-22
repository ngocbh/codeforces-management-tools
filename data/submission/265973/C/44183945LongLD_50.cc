#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	int i,n;
	cin >> n;
	if (n==1) printf("1");
	else if (n==2) printf("4");
	else if (n>=3){
		long long A[n+1],k;
		A[1]=1;
		A[2]=4;
		for (i=3;i<=n;i++)
		{
		A[i]=4*A[i-1]-A[i-2];
		}
		k=A[n] % 10000000007;
		cout << k;
	}
	
}
