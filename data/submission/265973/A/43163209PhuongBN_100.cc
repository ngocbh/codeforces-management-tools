#include <iostream>
 
using namespace std;
 
int addMod(int a, int b, int p) {
	a = a % p;
	b = b % p;
	int tmp = p - a;
	if (tmp > b) return a + b;
	else return b - tmp;
}
 
int main() {
	int num[10001];
	int i, j;
	int n, m;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> num[i];
	}
	int total = 0;
	int count = 0;
	for (i = 0; i < n; i++) {
		total = addMod(num[i], 0, m);
		if (total == 0)
			count+=1;
		for (j = i + 1; j < n; j++) {
			total = addMod(total, num[j], m);
			if (total == 0)
				count+=1;
		}
	}
	cout << count;
}