#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
int a[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/tung/cp/contest_1/.inp","r",stdin);
	freopen("/home/tung/cp/contest_1/.out","w",stdout);
	#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	int res=0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<=n;++j){
			res+=(((a[j]-a[i])%k)==0);
		}
	}
	cout<<res;
}