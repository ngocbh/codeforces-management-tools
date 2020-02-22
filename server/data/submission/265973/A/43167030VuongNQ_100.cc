#include <stdio.h>
#include <iostream>
using namespace std;
int n, k;
int a[10000];
int dem = 0;
int s = 0;
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		s = 0;
		for (int j = i; j < n; j++) {
			s += a[j];
			if (s % k == 0) dem++;
		}
	}

	cout << dem;
}