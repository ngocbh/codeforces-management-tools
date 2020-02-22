#include<bits/stdc++.h>
#define N 10010

using namespace std;

int n, k, a[N];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	int count = 0;
	for (int i=0; i<n; i++){
		int s = 0;
		for (int j=i; j<n; j++){	
			s += a[j];
			if (s%k==0){
				count ++;
			}
		}
	}
	cout << count;
}
