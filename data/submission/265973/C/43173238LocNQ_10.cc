<<<<<<< Updated upstream
#include <bits/stdc++.h>
using namespace std;

int n;
long long f[100001];
int m = 1000000007;
void input() {
	cin >> n;
}
void solve() {
	f[1] = 1;
	f[2] = 4;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] * 42;
		f[i] = f[i] % m;
	}
	cout << f[n];
}
int main() {
	input();
	solve();
=======
#include <bits/stdc++.h>
using namespace std;

int n;
long long f[100001];
int m = 1000000007;
void input() {
	cin >> n;
}
void solve() {
	f[1] = 1;
	f[2] = 4;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] * 42;
		f[i] = f[i] % m;
	}
	cout << f[n];
}
int main() {
	input();
	solve();
>>>>>>> Stashed changes
}