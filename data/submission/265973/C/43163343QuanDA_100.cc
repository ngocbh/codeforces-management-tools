<<<<<<< Updated upstream
#include <iostream>

#define MAX 100007
#define MOD 1000000007

using namespace std;

int n;
int a[MAX];
int b[MAX];

void input() {
	cin >> n;
}

int mod(int a) {
	if (a >= MOD) {
		return a - MOD;
	}
	return a;
}

void solve() {
	a[2] = 4;
	a[1] = 1;
	a[0] = 0;
	b[0] = 0;

	for (int i = 3; i <= n; i++) {
		b[i - 2] = mod(b[i-3] + a[i - 2]);
		a[i] = mod(mod(a[i-1]+mod(2 * a[i - 1])) + mod(2*b[i - 2]+1));
	}
	cout << a[n];
}



int main() {
	input();
	solve();
	return 0;
}
=======
#include <iostream>

#define MAX 100007
#define MOD 1000000007

using namespace std;

int n;
int a[MAX];
int b[MAX];

void input() {
	cin >> n;
}

int mod(int a) {
	if (a >= MOD) {
		return a - MOD;
	}
	return a;
}

void solve() {
	a[2] = 4;
	a[1] = 1;
	a[0] = 0;
	b[0] = 0;

	for (int i = 3; i <= n; i++) {
		b[i - 2] = mod(b[i-3] + a[i - 2]);
		a[i] = mod(mod(a[i-1]+mod(2 * a[i - 1])) + mod(2*b[i - 2]+1));
	}
	cout << a[n];
}



int main() {
	input();
	solve();
	return 0;
}
>>>>>>> Stashed changes
