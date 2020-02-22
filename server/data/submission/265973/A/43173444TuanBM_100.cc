#include<bits/stdc++.h>
#define MAX 10000

using namespace std;

int N; int K;
int a[MAX];
int b[MAX];

int main(){
	int dem = 0;
	cin>>N>>K;
	for (int i = 0; i<N;i++){
		cin>>a[i];
	}
	for (int i = 0; i<=N-1; i++){
		for (int j = i; j>=0;j--){
			b[j]+=a[i];
			if (b[j]%K == 0) dem+=1;
		}
	}
	cout<<dem;
}