<<<<<<< Updated upstream
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

typedef pair<int, int> iPair;
int n, m;
int ntplt, cnt;
vector<int> adj[MAX];
vector<int> c[MAX];
int tplt[MAX];
int maxc = 0;
iPair edge[MAX];

void input() {
	cin >> n >> m;
	int u, v, w;
	cnt = 0;
	ntplt = 0;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		maxc = max(maxc, w);
		if (w != -1) {
			adj[u].push_back(v);
			c[u].push_back(w);
			adj[v].push_back(u);
			c[v].push_back(w);
		}
		else {
			cnt++;
			edge[cnt] = make_pair(u, v);
		}
	}
}
void DFS(int u, int x) {
	tplt[u] = ntplt;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (tplt[v] == 0 && c[u][i] > x)
			DFS(v, x);
	}
}

bool check(int x) {
	ntplt = 0;
	for (int i = 1; i <= n; i++) 
		tplt[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (tplt[i] == 0) {
			ntplt++;
			DFS(i, x);
		}
	}
	for (int i = 1; i <= cnt; i++) {
		int u = edge[i].first;
		int v = edge[i].second;
		if (tplt[u] == tplt[v]) 
			return false;
	}
	return true;
}
void solve() {
	int kq = 9999999;
	int l = 0;
	int r = maxc;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			kq = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (kq == 9999999)
		cout << -1;
	else
		cout << kq;
}

int main() {
	input();
	solve();
}
=======
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

typedef pair<int, int> iPair;
int n, m;
int ntplt, cnt;
vector<int> adj[MAX];
vector<int> c[MAX];
int tplt[MAX];
int maxc = 0;
iPair edge[MAX];

void input() {
	cin >> n >> m;
	int u, v, w;
	cnt = 0;
	ntplt = 0;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		maxc = max(maxc, w);
		if (w != -1) {
			adj[u].push_back(v);
			c[u].push_back(w);
			adj[v].push_back(u);
			c[v].push_back(w);
		}
		else {
			cnt++;
			edge[cnt] = make_pair(u, v);
		}
	}
}
void DFS(int u, int x) {
	tplt[u] = ntplt;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (tplt[v] == 0 && c[u][i] > x)
			DFS(v, x);
	}
}

bool check(int x) {
	ntplt = 0;
	for (int i = 1; i <= n; i++) 
		tplt[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (tplt[i] == 0) {
			ntplt++;
			DFS(i, x);
		}
	}
	for (int i = 1; i <= cnt; i++) {
		int u = edge[i].first;
		int v = edge[i].second;
		if (tplt[u] == tplt[v]) 
			return false;
	}
	return true;
}
void solve() {
	int kq = 9999999;
	int l = 0;
	int r = maxc;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			kq = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (kq == 9999999)
		cout << -1;
	else
		cout << kq;
}

int main() {
	input();
	solve();
}
>>>>>>> Stashed changes
