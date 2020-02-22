<<<<<<< Updated upstream
#include<bits/stdc++.h>
#define N 100010
#define Q 1000000007
 
using namespace std;
 
int n, m;
int u[N], v[N];
int x[N], visit[N];
int parent[N], rk[N];
int res=0;
 
void makeSet(int x){
	parent[x] = x;
	rk[x] =  0;
}
 
int find(int x){
	if (parent[x]!=x){
		parent[x] = find(parent[x]);
	}
	return parent[x];
}
 
void merge(int x, int y){
	int rx = find(x);
	int ry = find(y);
	if (rk[rx]>rk[ry]){
		parent[ry] = rx;
	}else{
		parent[rx] = ry;
		if (rk[rx]==rk[ry]){
			rk[ry] += 1;
		}
	}
}
 
void setInit(){
	for (int i=0; i<=n; i++){
		makeSet(i);
	}
}
 
bool check(int k){
	setInit();
	for (int i=1; i<=k; i++){
		if (find(u[x[i]]) == find(v[x[i]])){
			return false;
		}
		merge(u[x[i]], v[x[i]]);
	}
	return true;
}
 
void TRY(int k){
	for (int i=x[k-1]+1; i<m; i++){
		if (visit[i]){
			visit[i] = 0;
			x[k] = i;
			
			if (k==n-1){
				if (check(k)){
					res++;
					if (res==Q){
						res = 0;
					}
				}
			}else{
				TRY(k+1);
			}
						
			visit[i] = 1;
		}
	}
}
 
int main(){
	cin >> n;
	int idx = 0;
	for (int i=1; i<n; i++){
		u[idx] = 2*i-1;
		v[idx++] = 2*i;
		u[idx] = 2*i-1;
		v[idx++] = 2*i+1;
		u[idx] = 2*i;
		v[idx++] = 2*i+2;
	}
	u[idx] = 2*n-1;
	v[idx++] = 2*n;
	m = idx; n *= 2;
	for (int i=0; i<m; i++){
		visit[i] =  1;
	}
	x[0] = -1;
	TRY(1);
	cout << res;
=======
#include<bits/stdc++.h>
#define N 100010
#define Q 1000000007
 
using namespace std;
 
int n, m;
int u[N], v[N];
int x[N], visit[N];
int parent[N], rk[N];
int res=0;
 
void makeSet(int x){
	parent[x] = x;
	rk[x] =  0;
}
 
int find(int x){
	if (parent[x]!=x){
		parent[x] = find(parent[x]);
	}
	return parent[x];
}
 
void merge(int x, int y){
	int rx = find(x);
	int ry = find(y);
	if (rk[rx]>rk[ry]){
		parent[ry] = rx;
	}else{
		parent[rx] = ry;
		if (rk[rx]==rk[ry]){
			rk[ry] += 1;
		}
	}
}
 
void setInit(){
	for (int i=0; i<=n; i++){
		makeSet(i);
	}
}
 
bool check(int k){
	setInit();
	for (int i=1; i<=k; i++){
		if (find(u[x[i]]) == find(v[x[i]])){
			return false;
		}
		merge(u[x[i]], v[x[i]]);
	}
	return true;
}
 
void TRY(int k){
	for (int i=x[k-1]+1; i<m; i++){
		if (visit[i]){
			visit[i] = 0;
			x[k] = i;
			
			if (k==n-1){
				if (check(k)){
					res++;
					if (res==Q){
						res = 0;
					}
				}
			}else{
				TRY(k+1);
			}
						
			visit[i] = 1;
		}
	}
}
 
int main(){
	cin >> n;
	int idx = 0;
	for (int i=1; i<n; i++){
		u[idx] = 2*i-1;
		v[idx++] = 2*i;
		u[idx] = 2*i-1;
		v[idx++] = 2*i+1;
		u[idx] = 2*i;
		v[idx++] = 2*i+2;
	}
	u[idx] = 2*n-1;
	v[idx++] = 2*n;
	m = idx; n *= 2;
	for (int i=0; i<m; i++){
		visit[i] =  1;
	}
	x[0] = -1;
	TRY(1);
	cout << res;
>>>>>>> Stashed changes
}