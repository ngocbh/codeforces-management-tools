<<<<<<< Updated upstream
#include <iostream>
using namespace std;

int d, n;
int a[128][128];
long long maxc = 0;

void input() {
	cin >> d >> n;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		a[x][y] = c;
	}
}

void solve() {
	int x0, y0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			long long sum = 0;
			int s1, e1;
			s1 = 0; e1 = 100;
			if (i - d > 0) {
				s1 = i - d;
			}
			if (i + d < 100) {
				e1 = i + d;
			}
			int s2, e2;
			s2 = 0; e2 = 100;
			if (j - d > 0) {
				s2 = j - d;
			}
			if (j + d < 100) {
				e2 = j + d;
			}
			for (int u = s1; u <= e1; u++) {
				for (int v = s2; v <= e2; v++) {
					sum += a[u][v];
				}
			}
			if (sum > maxc) {
				maxc = sum;
				x0 = i;
				y0 = j;
			}
		}
	}
	cout << x0 << " " << y0 << " " << maxc;
}

int main() {
	input();
	solve();
	return 0;
=======
#include <iostream>
using namespace std;

int d, n;
int a[128][128];
long long maxc = 0;

void input() {
	cin >> d >> n;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		a[x][y] = c;
	}
}

void solve() {
	int x0, y0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			long long sum = 0;
			int s1, e1;
			s1 = 0; e1 = 100;
			if (i - d > 0) {
				s1 = i - d;
			}
			if (i + d < 100) {
				e1 = i + d;
			}
			int s2, e2;
			s2 = 0; e2 = 100;
			if (j - d > 0) {
				s2 = j - d;
			}
			if (j + d < 100) {
				e2 = j + d;
			}
			for (int u = s1; u <= e1; u++) {
				for (int v = s2; v <= e2; v++) {
					sum += a[u][v];
				}
			}
			if (sum > maxc) {
				maxc = sum;
				x0 = i;
				y0 = j;
			}
		}
	}
	cout << x0 << " " << y0 << " " << maxc;
}

int main() {
	input();
	solve();
	return 0;
>>>>>>> Stashed changes
}