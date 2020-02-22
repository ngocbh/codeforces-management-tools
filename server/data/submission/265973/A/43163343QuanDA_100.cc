#include <iostream>

using namespace std;

int n, k;
int a[10010];
int q = 0;
void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum % k == 0) {
				q++;
			}
		}
	}
	cout << q;
}

int main() {
	input();
	solve();
	return 0;
}