#include<bits/stdc++.h>
#include<vector>
#define maxN 51
using namespace std;
vector<int> a[maxN];
int n;
int b[maxN];
int e[maxN];
int x[maxN];
int ans;
 
int r[maxN]; //r[v] rank of set v
int p[maxN]; //p[v] parent of v
long long rs;

void link(int x, int y){
	if(r[x]>r[y]) p[y]=x;
	else{
		p[x]=y;
		if(r[x]==r[y]) r[y] ++;
	}
}
void makeSet(int x){
	p[x]=x;
	r[x]=0;
}
int findSet(int x){
	if(x!=p[x]) p[x]=findSet(p[x]);
	return p[x];
}
void input(){
	cin>>n;
	for(int i = 1; i<=m; i++){
		int u=2*n;
		int v=1+(n-1)*3;
		for(int i=0; i<2*n; i++)
		{
			a[i].push_back(i+2);
			if(i%2)
			a[i].push_back(i+1);
			
		}
		
		
	
		b[i]=u;
		e[i]=v;	
	}
}
int check(int val, int k){
	//check if set edges (b[x[1]],e[x[1]]), .... (b[x[val]],e[x[val]]) make cycles or not
	for(int i = 1; i<=n; i++) makeSet(i);
	for(int j=1; j<k; j++){
		int u=b[x[j]];
		int v=e[x[j]];
		int ru=findSet(u);
		int rv=findSet(v);
		if(ru==rv) return 0;
		link(ru,rv);
	}
	if(findSet(b[val])==findSet(e[val])) return 0;
	return 1;
}
void solution(){
	ans++;
	//for(int i = 1; i<n; i++) cout<<"("<<b[x[i]]<<","<<e[x[i]]<<")"<<endl;
}
void TRY(int k){
	for(int v=x[k-1]+1; v<=m; v++){
		int ok=check(v,k);
		if(ok){
			x[k]=v;
			if(k==n-1) solution();
			else TRY(k+1);
		}
	}
}
void solve(){
	ans=0;
	x[0]=0;
	TRY(1);
	cout<<ans;
}
int main(){	
	input();
	solve();
}