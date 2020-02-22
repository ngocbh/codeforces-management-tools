#include <bits/stdc++.h>

using namespace std;

const int NMAX = (int) 1e5 + 5;
const long long MODULO = (long long) 1e9 + 7;

int n;
long long c[NMAX];
long long res;

int main() {
	cin >> n;
	c[0] = 1;
	for (int i = 1; i < n; i++) {
		c[i] = 1;
		for (int j = 0; j < i; j++) {
			c[i] = (c[i] + c[j] * ((i - j) * 2)) % MODULO;
		}
	}
	res = 0;
	for (int i = 0; i < n; i++) {
		res = (res + c[i]) % MODULO;
		// cout << res << endl;
	}
	 cout << res << endl;
	// system("pause");
	return 0;
}
