<<<<<<< Updated upstream
#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0;
int a[10000];
int sum;
void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void solve() {
	cnt = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum % k == 0)
				cnt++;
		}
	}
	cout << cnt;
}
int main() {
	input();
	solve();
=======
#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0;
int a[10000];
int sum;
void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void solve() {
	cnt = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum % k == 0)
				cnt++;
		}
	}
	cout << cnt;
}
int main() {
	input();
	solve();
>>>>>>> Stashed changes
}