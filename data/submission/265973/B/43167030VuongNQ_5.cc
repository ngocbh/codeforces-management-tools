<<<<<<< Updated upstream
#include <bits/stdc++.h>
using namespace std;

int d;
int n;
int x[105], y[105], c[105];
int temp = 0;
int xx = 0, yy = 0, rs = 0;
void input() {
	cin >> d >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> c[i];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	input();
	for (int j = 1; j <= 100; j++) {
		for (int i = 1; i <= 100; i++) {
			temp = 0;
			for (int k = 1; k <= n; k++) {
				int z = max(abs(x[k] - i), abs(y[k] - j));
				if (z <= d) {
					temp += c[k];
				}
			}

			if (temp > rs) {
				xx = i;
				yy = j;
				rs = temp;
			}
		}
	}

	printf("%d %d %d", xx, yy, rs);
=======
#include <bits/stdc++.h>
using namespace std;

int d;
int n;
int x[105], y[105], c[105];
int temp = 0;
int xx = 0, yy = 0, rs = 0;
void input() {
	cin >> d >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> c[i];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	input();
	for (int j = 1; j <= 100; j++) {
		for (int i = 1; i <= 100; i++) {
			temp = 0;
			for (int k = 1; k <= n; k++) {
				int z = max(abs(x[k] - i), abs(y[k] - j));
				if (z <= d) {
					temp += c[k];
				}
			}

			if (temp > rs) {
				xx = i;
				yy = j;
				rs = temp;
			}
		}
	}

	printf("%d %d %d", xx, yy, rs);
>>>>>>> Stashed changes
}