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
	int c[100001];
	int n;
	int i;
	int p = 1000000007;
	cin >> n;
	c[0] = 1;
	c[1] = 1;
	c[2] = 4;
	int s = 1;
	for (i = 3; i <= n; i++) {
		c[i] = 0;
		for (int k = 1; k <= 3; k++) {
			c[i] = addmod(c[i], c[i - 1], p);
		}
		c[i] = addmod(c[i], s, p);
		c[i] = addmod(c[i], s, p);
		c[i] = addmod(c[i], 1, p);
		s = addmod(s, c[i-1], p);
	}
	cout << c[n];
	//system("pause");
}