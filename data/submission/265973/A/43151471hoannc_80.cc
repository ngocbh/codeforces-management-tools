<<<<<<< Updated upstream
#include <stdio.h>
#define MAX 10001

int N, K;
int a[MAX];
int sum, res;

void input(){
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
	}
}

int easySequence(){
	
	res = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			sum = 0;
			for(int k=j; k<=i; k++){
				sum+= a[k];
			}
			if(sum%K==0){
				res++;
				}
			}
	}
	
	return res;
}

int main(){
	input();
	printf("%d", easySequence());
	return 0;
}
=======
#include <stdio.h>
#define MAX 10001

int N, K;
int a[MAX];
int sum, res;

void input(){
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
	}
}

int easySequence(){
	
	res = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			sum = 0;
			for(int k=j; k<=i; k++){
				sum+= a[k];
			}
			if(sum%K==0){
				res++;
				}
			}
	}
	
	return res;
}

int main(){
	input();
	printf("%d", easySequence());
	return 0;
}
>>>>>>> Stashed changes
