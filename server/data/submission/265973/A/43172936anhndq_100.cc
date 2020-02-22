#include<iostream>
using namespace std;
//day con lon nhat
int n,k;
int a[10000];
int s[10000];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)	cin>>a[i];
	int count = 0;
	for(int i=0;i<=n-1;i++){
		for(int j=i;j>=0;j--){
			s[i]+=a[j];
			if(s[i]%k==0) count++;
		}
	}
	cout<<count;
	return 0;
}