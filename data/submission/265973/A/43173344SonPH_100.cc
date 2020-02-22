<<<<<<< Updated upstream
#include <stdio.h>
#define N 10000

int n;
int k;
int a[N];
int q;
int sum;

void input(){
	scanf("%d%d", &n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
}

int solve(){
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = i; j < n; j++){
			sum += a[j];
			if(sum%k == 0)
				q++;	
		}
	}
	printf("%d", q);
}
int main(){
	int q= 0;
	input();
	solve();
	
=======
#include <stdio.h>
#define N 10000

int n;
int k;
int a[N];
int q;
int sum;

void input(){
	scanf("%d%d", &n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
}

int solve(){
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = i; j < n; j++){
			sum += a[j];
			if(sum%k == 0)
				q++;	
		}
	}
	printf("%d", q);
}
int main(){
	int q= 0;
	input();
	solve();
	
>>>>>>> Stashed changes
}