#include<bits/stdc++.h>
using namespace std;

#define MAXN 10001

int n, k;
int A[MAXN];

void input(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
}

void solve(){
	int sat = 0;

	for(int i = 0;i < n; i++){
		int sum = 0;
		for (int j = i; j < n; j++){
			sum += A[j];
			if ((sum % k) == 0){
				sat++;
			}
		}
	}

	cout << sat << endl;
}
int main(){
	input();
	solve();
	return 0;
}