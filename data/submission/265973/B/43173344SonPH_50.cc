<<<<<<< Updated upstream
#include "stdio.h"
#define MAX 105

int A[MAX][MAX];   //map
int d;	//ban kinh
int n;  //so nha chuoi

int xs;
int ys;
int s;	//so chuoi tieu diet

void input(){
	scanf("%d%d", &d,&n);
	for(int i = 1; i <= n; i++){
		int x,y,c;
		scanf("%d%d%d", &x, &y,&c);
		A[x][y] = c;
	}
}

int solve(){
	for(int i = d + 1; i <= 100 - d; i++){
		for(int j = d + 1; j <= 100 - d; j++){
			int temp = 0;
			for(int k = i - d; k <= i + d; k++){
				for(int l = j - d; l <= j + d; l++){
					temp+=A[k][l];
				}
			}
//			printf("o (%d,%d) co s = %d\n", i, j, temp);
			if(temp >= s){
				s = temp;
				xs = i;
				ys = j;
			}	
		}
	}
	printf("%d %d %d", xs, ys, s);
}
int main(){
	int xs = 0;
	int ys = 0;
	int s = 0;
	input();
	solve();
	
=======
#include "stdio.h"
#define MAX 105

int A[MAX][MAX];   //map
int d;	//ban kinh
int n;  //so nha chuoi

int xs;
int ys;
int s;	//so chuoi tieu diet

void input(){
	scanf("%d%d", &d,&n);
	for(int i = 1; i <= n; i++){
		int x,y,c;
		scanf("%d%d%d", &x, &y,&c);
		A[x][y] = c;
	}
}

int solve(){
	for(int i = d + 1; i <= 100 - d; i++){
		for(int j = d + 1; j <= 100 - d; j++){
			int temp = 0;
			for(int k = i - d; k <= i + d; k++){
				for(int l = j - d; l <= j + d; l++){
					temp+=A[k][l];
				}
			}
//			printf("o (%d,%d) co s = %d\n", i, j, temp);
			if(temp >= s){
				s = temp;
				xs = i;
				ys = j;
			}	
		}
	}
	printf("%d %d %d", xs, ys, s);
}
int main(){
	int xs = 0;
	int ys = 0;
	int s = 0;
	input();
	solve();
	
>>>>>>> Stashed changes
}