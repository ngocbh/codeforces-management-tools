<<<<<<< Updated upstream
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
const int MOD=1e9+7;
ll f[N],g[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/tung/cp/contest_1/.inp","r",stdin);
	freopen("/home/tung/cp/contest_1/.out","w",stdout);
	#endif
	ll x;
	cin>>x;
	f[1]=1;
	f[2]=4;
	g[1]=1;
	g[2]=5;
	for(int i=3;i<N;++i){
		f[i]=((3*f[i-1])%MOD+(2*g[i-2])%MOD+1)%MOD;
		g[i]=(g[i-1]+f[i])%MOD;
	}
	cout<<f[x];
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
const int MOD=1e9+7;
ll f[N],g[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/tung/cp/contest_1/.inp","r",stdin);
	freopen("/home/tung/cp/contest_1/.out","w",stdout);
	#endif
	ll x;
	cin>>x;
	f[1]=1;
	f[2]=4;
	g[1]=1;
	g[2]=5;
	for(int i=3;i<N;++i){
		f[i]=((3*f[i-1])%MOD+(2*g[i-2])%MOD+1)%MOD;
		g[i]=(g[i-1]+f[i])%MOD;
	}
	cout<<f[x];
>>>>>>> Stashed changes
}