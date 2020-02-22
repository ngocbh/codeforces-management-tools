<<<<<<< Updated upstream
#include <iostream>
#include <vector>
#define MAXN 51
using namespace std; 
 
vector <int> a[MAXN]; 
int n, m; 
int b[MAXN], e[MAXN], x[MAXN]; 
int ans; 
 
int r[MAXN]; // r[v] rank of set v
int p[MAXN]; // p[v] parent of v
long long rs; 
 
void link(int x, int y) {
	if (r[x] > r[y]) 
		p[y] = x; 
	else 
	{
		p[x] = y; 
		if (r[x] == r[y])
			r[y]++; 
	}
}
 
void makeSet(int x) {
	p[x] = x; 
	r[x] = 0; 
}
 
int findSet(int x) {
	if (x != p[x])
		p[x] = findSet(p[x]); 
	return p[x]; 
}
 
void input() {
    ios::sync_with_stdio(false);
	cin >> n >> m; 
	for (int i = 1; i <= m; i++) {
		int u, v; 
		cin >> u >> v; 
		a[u].push_back(v); 
		a[v].push_back(u); 
		b[i] = u; 
		e[i] = v;
	}
}
 
int check(int val, int k) {
	// check if set edges (b[x[1]], e[x[1]]), ... (b[x[val]], e[x[val]]) make cycles or not 
	for (int i = 1; i <= n; i++) 
		makeSet(i); 
	for (int j = 1; j < k; j++) {
		int u = b[x[j]]; 
		int v = e[x[j]]; 
		int ru = findSet(u); 
		int rv = findSet(v); 
		if (ru == rv) 
			return 0;
		link(ru, rv); 
	}
	if (findSet(b[val]) == findSet(e[val])) 
		return 0; 
	return 1; 
}
 
void solution() {
	ans++;
}
 
void TRY(int k) {
	for (int v = x[k - 1] + 1; v <= m; v++) {
		int ok = check(v, k); 
		if (ok) {
			x[k] = v; 
			if (k == n - 1) solution(); 
			else TRY(k+1);
		}
	}
}
 
void solve() {
	ans = 0; 
	x[0] = 0; 
	TRY(1); 
	cout << ans; 
}
 
int main() {
//	freopen("input.txt", "r", stdin); 
	input(); 
	solve(); 
	return 0; 
}
=======
#include <iostream>
#include <vector>
#define MAXN 51
using namespace std; 
 
vector <int> a[MAXN]; 
int n, m; 
int b[MAXN], e[MAXN], x[MAXN]; 
int ans; 
 
int r[MAXN]; // r[v] rank of set v
int p[MAXN]; // p[v] parent of v
long long rs; 
 
void link(int x, int y) {
	if (r[x] > r[y]) 
		p[y] = x; 
	else 
	{
		p[x] = y; 
		if (r[x] == r[y])
			r[y]++; 
	}
}
 
void makeSet(int x) {
	p[x] = x; 
	r[x] = 0; 
}
 
int findSet(int x) {
	if (x != p[x])
		p[x] = findSet(p[x]); 
	return p[x]; 
}
 
void input() {
    ios::sync_with_stdio(false);
	cin >> n >> m; 
	for (int i = 1; i <= m; i++) {
		int u, v; 
		cin >> u >> v; 
		a[u].push_back(v); 
		a[v].push_back(u); 
		b[i] = u; 
		e[i] = v;
	}
}
 
int check(int val, int k) {
	// check if set edges (b[x[1]], e[x[1]]), ... (b[x[val]], e[x[val]]) make cycles or not 
	for (int i = 1; i <= n; i++) 
		makeSet(i); 
	for (int j = 1; j < k; j++) {
		int u = b[x[j]]; 
		int v = e[x[j]]; 
		int ru = findSet(u); 
		int rv = findSet(v); 
		if (ru == rv) 
			return 0;
		link(ru, rv); 
	}
	if (findSet(b[val]) == findSet(e[val])) 
		return 0; 
	return 1; 
}
 
void solution() {
	ans++;
}
 
void TRY(int k) {
	for (int v = x[k - 1] + 1; v <= m; v++) {
		int ok = check(v, k); 
		if (ok) {
			x[k] = v; 
			if (k == n - 1) solution(); 
			else TRY(k+1);
		}
	}
}
 
void solve() {
	ans = 0; 
	x[0] = 0; 
	TRY(1); 
	cout << ans; 
}
 
int main() {
//	freopen("input.txt", "r", stdin); 
	input(); 
	solve(); 
	return 0; 
}
>>>>>>> Stashed changes
