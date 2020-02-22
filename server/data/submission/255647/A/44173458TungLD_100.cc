#include<bits/stdc++.h>
using namespace std;
int n;
char a[15000], b[150000];
void xaulap(int n, char a[]){
	int i = 0,j=0;
	while(i!=n){
		b[j] = a[i];
		while(a[i] == b[j]) i++;
		j++;
	}
		for(int i = 0;i<j;++i)
	{
		cout <<b[i];
	}
}
int main(){
	gets(a);
	int n = strlen(a);
	xaulap(n,a);

	return 0;
}