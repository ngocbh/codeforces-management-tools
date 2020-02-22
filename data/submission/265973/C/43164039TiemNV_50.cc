#include<iostream>
#define x 10000007
using namespace std; 
int n; 
int aa[100001];
int modAdd(int a, int b) {
	a = a % x;
	b = b % x;
	int tem1 = x - a;
	if (tem1 > b) return a + b;
	return b - tem1;
} 
int modNhan(int a, int b) {
	if (a == 1)  return b % x;
	if (b == 1) return a % x;
	if (a > b) {
		int tem = a; a = b; b = tem;
	}
	int c = modNhan(a / 2, b);
	c = modAdd(c, c);
	if (a % 2 == 0) return c;
	else {
		return modAdd(c, b);
	}	
}

int main() {
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		if (i == 1) {

			aa[i]=  1;
		}
		if (i == 2) {

			aa[i] = 4;
		}
		if (i > 2) {
			int tem2 = aa[i - 2];
			int tem =(aa[i - 1] - aa[i - 2]);
		
			tem2 = modAdd(aa[i - 2], tem2);
			tem2 = modAdd(aa[i - 2], tem2);

			int t =  modAdd(tem, tem);
			t = modAdd(t, tem);
			t = modAdd(t, tem);

			t  = modAdd(t, tem2);

			aa[i] = t;
		}
	}
	cout << aa[n];
	return 0;
}