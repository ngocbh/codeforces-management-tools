#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,ll> > iii;
ll f[101][101];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/tung/cp/contest_1/.inp","r",stdin);
	freopen("/home/tung/cp/contest_1/.out","w",stdout);
	#endif
	ll d,n;
	cin>>d>>n;
	while(n--){
		ll x,y,c;
		cin>>x>>y>>c;
		for(ll i=1;i<=100;++i){
			for(ll j=1;j<=100;++j){
				if(max(abs(i-x),abs(j-y))<=d){
					f[i][j]+=c;
				}
			}
		}
	}
	iii res={0,{0,0}};
	for(ll i=1;i<=100;++i){
		for(ll j=1;j<=100;++j){
			res=max(res,{f[i][j],{-i,-j}});
		}
	}
	cout<<-res.second.first<<' '<<-res.second.second<<' '<<res.first;
}