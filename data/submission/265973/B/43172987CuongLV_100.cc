<<<<<<< Updated upstream
#include<bits/stdc++.h>
#define N 20010

using namespace std;

int n, d, a[101][101];

int main(){
	ios::sync_with_stdio(false);
	cin >> d >> n;
	for (int i=0; i<n; i++){
		int s, t;
		cin >> s >> t;
		cin >> a[s][t];
	}
	int x0, y0, s0 = 0;
	for (int i=1; i<=100; i++){
		for (int j=1; j<=100; j++){
			int s = 0;
			for(int u = 1; u<=100; u++){
				for (int v = 1; v<=100; v++){
					if (max(abs(u-i), abs(v-j))<=d){
						s += a[u][v];
					}
				}
			}
			if (s>s0){
				s0=s;
				x0 = i;
				y0 = j;
			}
		}
	}
	cout << x0 << " " << y0 << " " << s0;
=======
#include<bits/stdc++.h>
#define N 20010

using namespace std;

int n, d, a[101][101];

int main(){
	ios::sync_with_stdio(false);
	cin >> d >> n;
	for (int i=0; i<n; i++){
		int s, t;
		cin >> s >> t;
		cin >> a[s][t];
	}
	int x0, y0, s0 = 0;
	for (int i=1; i<=100; i++){
		for (int j=1; j<=100; j++){
			int s = 0;
			for(int u = 1; u<=100; u++){
				for (int v = 1; v<=100; v++){
					if (max(abs(u-i), abs(v-j))<=d){
						s += a[u][v];
					}
				}
			}
			if (s>s0){
				s0=s;
				x0 = i;
				y0 = j;
			}
		}
	}
	cout << x0 << " " << y0 << " " << s0;
>>>>>>> Stashed changes
}