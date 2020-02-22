#include<iostream>
using namespace std; 
int a[101][101];
int n; 
int d;
void input() {
	cin >> d >> n; 
	int x, y, z; 
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		a[x][y] = z; 
	}
}
int mm(int a,int b){
	return a > b ? a : b; 
}
int min(int a,int b) {
	return a < b ? a : b;
}

void ham() {
	int mx = 0; 
	int xx = 0, yy = 0; 
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			int t = 0;
			for (int u = mm(0, i - d); u <= min(100, i + d); u++) {
				for (int v = mm(0, j - d); v <= min(100, j + d); v++) {
					t += a[u][v];
				}
			 }
			if (t > mx) {
				xx = i;
				yy = j; 
				mx = t; 
			}
		}
	}
	cout << xx << " " << yy << " " << mx;
}
int main() {
	input();
	ham(); 
	return 0;
}