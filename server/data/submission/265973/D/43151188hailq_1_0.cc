#include <iostream>
#include<vector>
#define MAX 2001
using namespace std;

int m,n;
int a[MAX];
int b[MAX];
int c[MAX];

input(){
	cin >> m >>n;
	for(int i=1; i<=m; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
}
int main(){
	input();
	cout << 4;
}



