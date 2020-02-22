#include <iostream>

using namespace std;
#define MAX 500

int d;
int n;
int a[MAX][MAX] = {0};
int f, f_max = 0;
int x1 = 0, y1 = 0;

void input(){
	cin >> d >> n;
	for(int i=1; i<=n; i++){
		int x, y;
		cin >> x >> y;
		x = x +150;
		y = y + 150;
		cin >> a[x][y];
	}
}

int main(){
	input();
	for(int x0=1+150; x0<=100+150; x0++){
		for(int y0=1+150; y0<=100+150; y0++){
			f = 0;
			for(int i=x0-d; i<=x0+d; i++){
				for(int j=y0-d; j<=y0+d; j++){
					f = f + a[i][j];
				}
			}
			if(f>f_max){
				x1 = x0 - 150;
				y1 = y0 - 150;
				f_max = f;
			} 
		}
	}
	cout << x1 << " " << y1 << " " << f_max;
}