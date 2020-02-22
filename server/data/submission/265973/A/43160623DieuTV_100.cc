#include <iostream>

using namespace std;

int addmod(int a, int b, int p) {
	a = a % p;
	b = b % p;
	int tmp = p - a;
	if (tmp > b) return a + b;
	else return b - tmp;
}

int main() {
	int a[10001];
	int i, j;
	int n, k;
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int s = 0;
	int ans = 0;
	for (i = 1; i <= n; i++) {
		s = addmod(a[i], 0, k);
		if (s == 0)
			ans++;
		for (j = i + 1; j <= n; j++) {
			s = addmod(s, a[j], k);
			if (s == 0)
				ans++;
		}
	}
	cout << ans;
	//system("pause");
}