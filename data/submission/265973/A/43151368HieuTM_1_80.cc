<<<<<<< Updated upstream
#include <stdio.h>
#include <conio.h>

int main() {
	int N, K;
	int i, j;
	int tong;
	int bd = 0;
	
	scanf("%d", &N);
	scanf("%d", &K);
	
	int a[N];
	
	for( i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}	
	
	for( i=0; i<N; i++){
		for( j=i; j<N; j++){
			tong = 0;
			for(int b=i; b<=j; b++){
				tong = tong + a[b];
			}
			if((tong%K) == 0) {
				bd++;
			}
		}	
	}

	printf("%d", bd);
=======
#include <stdio.h>
#include <conio.h>

int main() {
	int N, K;
	int i, j;
	int tong;
	int bd = 0;
	
	scanf("%d", &N);
	scanf("%d", &K);
	
	int a[N];
	
	for( i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}	
	
	for( i=0; i<N; i++){
		for( j=i; j<N; j++){
			tong = 0;
			for(int b=i; b<=j; b++){
				tong = tong + a[b];
			}
			if((tong%K) == 0) {
				bd++;
			}
		}	
	}

	printf("%d", bd);
>>>>>>> Stashed changes
}