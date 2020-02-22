#include<iostream>
using namespace std;
long long get(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 4;
	else return (4 * get(n - 1) - get(n - 2)) % 1000000007;
}
int main() {
	long long n;
	cin >> n;
	long long f1, f2, f;
	f1 = 1; f2 = 4;
	if (n == 1) cout << 1;
	else if (n == 2) cout << 4;
	else {
		for (int i = 2; i < n; i++) {
			f = (4 * f2 - f1) % 1000000007;
			f1 = f2;
			f2 = f;
		}
		cout << f;
	}
	//system("pause");
	return 0;
}