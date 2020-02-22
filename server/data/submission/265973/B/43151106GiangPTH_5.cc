#include <iostream>
using namespace std; 
#define MAX 100
int d, n; 
int a[MAX][MAX]; 
int c[MAX][MAX]; 
int cmax = 0; 
int xmax = 0; 
int ymax = 0; 
void input() {
	cin >> d >> n;
	int x, y, z; 
	for (int i = 1; i <= n; i++) {
			cin >> x >> y >> z; 
			a[x][y] = z;
	}
 }
void solve() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			c[i][j] = 0; 
		}
	}

	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; j <= MAX; j++) {
			for (int tx = i - d; tx <= i + d; tx++) {
				if (tx <= 0 || tx > MAX) continue; 
				for (int ty = j - d; ty <= j + d; ty++) {
					if (ty <= 0 || ty > MAX) continue;
					c[i][j] += a[tx][ty]; 
				}
			}
			if (c[i][j] > cmax) {
				cmax = c[i][j]; 
				xmax = i; 
				ymax = j; 
			}
		}
	}
	cout << xmax << ' ' << ymax << ' ' << cmax; 
	
}
int main() {
//	freopen("input.txt", "r", stdin); 
	input(); 
	solve(); 
	return 0; 
}