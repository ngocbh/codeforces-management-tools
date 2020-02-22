#include <bits/stdc++.h>
using namespace std;

int n, d;
int a[101][101];
int f_best;
int x_best;
int y_best;
void input() {
	cin >> d >> n;
	int x, y, z;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		a[x][y] = z;
	}
}
int tinh(int x, int y) {
	int xmax = min(100, d + x);
	int ymax = min(100, d + y);
	int sum = 0;
	for (int i = max(1, x - d); i <= xmax; i++) {
		for (int j = max(1, y - d); j <= ymax; j++) {
			sum += a[i][j];
		}
	}
	return sum;
}
void solve() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			int sum = tinh(i, j);
			if (sum > f_best) {
				x_best = i;
				y_best = j;
				f_best = sum;
			}
		}
	}
	cout << x_best << " " << y_best << " " << f_best;
}
int main() {
	input();
	solve();
}