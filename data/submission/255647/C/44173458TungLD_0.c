#include<conio.h>
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int n;
int tho[1000000],khach[1000000],danhdau[1000000];
int minf=-600000000;
int temp=0
void ghepcap(int k){
	if(k=n){
		for(int i =0; i<n;++i){
			if(danhdau[i]=0){
				temp+=abs(tho[k]-khach[i]);
				minf = (minf<temp)?minf:temp;
				temp-=abs(tho[k]-khach[i]);
				return
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(danhdau[i] = 0){
			temp += abs(tho[k]-khach[i]);
			danhdau[i] = 1;
			ghepcap(k+1);
			danhdau[i] = 0;
			temp = temp -abs[tho[k]-khach[i];
		}
	}
}
int main(){
	cin >> n ;
	tho[0] = 0;
	khach[0] = 0;
	danhdau[0]=0;
	for(int i =1;i<= n;++i){
		cin >>tho[i];
		danhdau[i] = 0;
	}
	for(int i=1; i<=n;++i){
		cin >> khach[i];
	}
	ghepcap(1);
	cout<<minf<<endl;
	return 0;
}