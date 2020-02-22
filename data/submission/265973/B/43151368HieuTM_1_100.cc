<<<<<<< Updated upstream
#include <iostream>
#define MAX 500

using namespace std;

int d, n;
int a[MAX][MAX] = {0};
int f, f_max = 0;
int xout = 0, yout = 0;

void input(){
	cin >> d >> n;
	for(int i=1; i<=n; i++){
		int x, y, c;
		cin >> x >> y >> c;
		x = x +150;
		y = y + 150;
		a[x][y] = c;
	}
}

void TRY(){
	for(int xd = 151; xd <= 250; xd++){
		for(int yd=151; yd<=250; yd++){
			f = 0;
			for(int i=xd-d; i<=xd+d; i++){
				for(int j=yd-d; j<=yd+d; j++){
					f = f + a[i][j];
				}
			}
			if(f>f_max){
				xout = xd - 150;
				yout = yd - 150;
				f_max = f;
			} 
		}
	}
}

void solve(){
	input();
	TRY();
}

int main(){
	
	solve();
	
	cout<<xout<<" "<<yout<<" "<<f_max;
=======
#include <iostream>
#define MAX 500

using namespace std;

int d, n;
int a[MAX][MAX] = {0};
int f, f_max = 0;
int xout = 0, yout = 0;

void input(){
	cin >> d >> n;
	for(int i=1; i<=n; i++){
		int x, y, c;
		cin >> x >> y >> c;
		x = x +150;
		y = y + 150;
		a[x][y] = c;
	}
}

void TRY(){
	for(int xd = 151; xd <= 250; xd++){
		for(int yd=151; yd<=250; yd++){
			f = 0;
			for(int i=xd-d; i<=xd+d; i++){
				for(int j=yd-d; j<=yd+d; j++){
					f = f + a[i][j];
				}
			}
			if(f>f_max){
				xout = xd - 150;
				yout = yd - 150;
				f_max = f;
			} 
		}
	}
}

void solve(){
	input();
	TRY();
}

int main(){
	
	solve();
	
	cout<<xout<<" "<<yout<<" "<<f_max;
>>>>>>> Stashed changes
}