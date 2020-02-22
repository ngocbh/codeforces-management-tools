#include<iostream>
using namespace std;
int N, K, A[10000], f[10000],S=0,gn[10000];
int main() {
	cin >> N >> K;
	int i, h;
	f[0] = 0;
	gn[0] = 0;
	for (i = 0; i < N; i++) {
		cin >> A[i];
		f[i+1] = f[i]+A[i];
		gn[i] = 0;
	}
	for (i = 0; i < N; i++) {
		if (f[i+1] % K == 0) {
			gn[i + 1] = S + 1;
		}
		else {
			h = i + 1;
			for (int j = 0; j < i; j++) {
				f[h] -= A[j];
				if (f[h] % K == 0) gn[h]++;
			}
		}
		S += gn[i + 1];
	}
	cout << S;
	//system("pause");
	return 0;
}