<<<<<<< Updated upstream
#include<bits/stdc++.h>
using namespace std;
#define MAXN 120
int n;
int d;
int matric[MAXN][MAXN];
int bestx, besty, bests;


void input(){
	for (int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			matric[i][j] = 0;
		}
	}
	cin >> d >> n;

	for (int i = 0; i < n; i++){
		int x, y, s;
		cin >> x >> y >> s;
		matric[x][y] = s;
	}
}
int max(int x, int y){
	return (x > y)? x:y;
}
int min(int x, int y){
	return (x > y) ? y : x;
}


void solve(){
	
	bests = 0;
	for (int i = 1; i <= 100; i++){
		for (int j = 1; j <= 100 ; j++){
			int tmp = 0;
			for (int k1 = max(i-d, 0); k1 <= min(i+d, 100); k1++){
				for (int k2 = max(j-d, 0); k2 <= min(j+d, 100); k2++){
					tmp += matric[k1][k2];
				}
			}

			if (tmp > bests){
				bests = tmp;
				bestx = i;
				besty = j;
			}

		}
	}
	cout << bestx << "\t" <<besty << "\t" << bests << endl;
}
int main(){
	input();
	solve();
	return 0;
=======
#include<bits/stdc++.h>
using namespace std;
#define MAXN 120
int n;
int d;
int matric[MAXN][MAXN];
int bestx, besty, bests;


void input(){
	for (int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			matric[i][j] = 0;
		}
	}
	cin >> d >> n;

	for (int i = 0; i < n; i++){
		int x, y, s;
		cin >> x >> y >> s;
		matric[x][y] = s;
	}
}
int max(int x, int y){
	return (x > y)? x:y;
}
int min(int x, int y){
	return (x > y) ? y : x;
}


void solve(){
	
	bests = 0;
	for (int i = 1; i <= 100; i++){
		for (int j = 1; j <= 100 ; j++){
			int tmp = 0;
			for (int k1 = max(i-d, 0); k1 <= min(i+d, 100); k1++){
				for (int k2 = max(j-d, 0); k2 <= min(j+d, 100); k2++){
					tmp += matric[k1][k2];
				}
			}

			if (tmp > bests){
				bests = tmp;
				bestx = i;
				besty = j;
			}

		}
	}
	cout << bestx << "\t" <<besty << "\t" << bests << endl;
}
int main(){
	input();
	solve();
	return 0;
>>>>>>> Stashed changes
}