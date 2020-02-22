/*
inputCopy
1
2
4 4 10
6 6 20
outputCopy
5 5 30
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[101][101];
int sum(int x,int y,int d) {
	int res = 0;
	for(int i=x-d; i<=x+d; i++) {
		for(int j=y-d;j<=y+d;j++){
			if(i>=0&&j>=0&&i<=100&&j<=100){
				res+=arr[i][j];
			}
		}
	}
	return res;
}
int main() {
	//input
	int d;
	cin>>d;
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		arr[x][y]=z;
	}
	//handle
	int sx,sy,sz;
	for(int i=0; i<=100; i++) {
		for(int j=0; j<=100; j++) {
			int temp = sum(i,j,d);
			if(sz < temp){
				sz = temp;
				sx = i;
				sy= j;
			}		
		}
	}
	//show output
	cout<<sx<<" "<<sy<<" "<<sz;

	return 0;
}

