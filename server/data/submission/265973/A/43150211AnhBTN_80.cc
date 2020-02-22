#include<iostream>
using namespace std;
#define max 10005
int main(){
	int N;
	int K;
	int a[max];
	cin>>N>>K;
	int Q=0;
	for(int i=1; i<=N; i++) cin>>a[i];
	for(int i=1; i<=N; i++){
		int t=1;
		while(i+t-1<=N){
			int tong = 0;
			for(int k=t; k<=i+t-1; k++){
				tong = tong + a[k];
			}
			if(tong%K == 0) Q++;
			t++;
		}
	}
	cout<<Q;
}