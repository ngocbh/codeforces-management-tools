<<<<<<< Updated upstream
#include <iostream>

using namespace std;

int x[101][101];

int max2(int a, int b) {
	if (a < b)
		return b;
	else
		return a;
}

int min2(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int main() {
	int n, d, i, j, k, l;
	int x1, y1, c1;
	c1 = -1;
	cin >> d >> n;
	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			x[i][j] = 0;
		}
	}
	for (i = 1; i <= n; i++) {
		int a, b, cc;
		scanf("%d%d%d", &a, &b, &cc);
		x[a][b] = cc;
		//cout <<"**"<< x[a][b];
	}
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			int ctmp = 0;
			for (k = max2(i - d, 0); k <= min2(i+d,100); k++) {
				for (l = max2(j - d, 0); l <= min2(j+d,100); l++) {
					ctmp += x[k][l];
				}
			}
			if (ctmp > c1) {
				c1 = ctmp;
				x1 = i;
				y1 = j;
			}
		}
	}
	cout << x1 << " " << y1 << " " << c1;
	//system("pause");
=======
#include <iostream>

using namespace std;

int x[101][101];

int max2(int a, int b) {
	if (a < b)
		return b;
	else
		return a;
}

int min2(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int main() {
	int n, d, i, j, k, l;
	int x1, y1, c1;
	c1 = -1;
	cin >> d >> n;
	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			x[i][j] = 0;
		}
	}
	for (i = 1; i <= n; i++) {
		int a, b, cc;
		scanf("%d%d%d", &a, &b, &cc);
		x[a][b] = cc;
		//cout <<"**"<< x[a][b];
	}
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			int ctmp = 0;
			for (k = max2(i - d, 0); k <= min2(i+d,100); k++) {
				for (l = max2(j - d, 0); l <= min2(j+d,100); l++) {
					ctmp += x[k][l];
				}
			}
			if (ctmp > c1) {
				c1 = ctmp;
				x1 = i;
				y1 = j;
			}
		}
	}
	cout << x1 << " " << y1 << " " << c1;
	//system("pause");
>>>>>>> Stashed changes
}