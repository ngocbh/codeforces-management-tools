<<<<<<< Updated upstream
#include <stdio.h>
#include <conio.h>
#define MAX 100000
int main() {
	int n, i, j, k, sum, subsum = 0, count = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	int a[MAX];
	for( i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}	
	
	for( i = 0; i < n; i++){
		for( j = i; j < n; j++){
			sum = 0;
			for(int x = i; x <= j; x++){
				sum = sum + a[x];
			}
			subsum = sum % 100000007;
			if(subsum % k == 0) {
				count++;
			}
		}
		
	}

	printf("%d", count);
=======
#include <stdio.h>
#include <conio.h>
#define MAX 100000
int main() {
	int n, i, j, k, sum, subsum = 0, count = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	int a[MAX];
	for( i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}	
	
	for( i = 0; i < n; i++){
		for( j = i; j < n; j++){
			sum = 0;
			for(int x = i; x <= j; x++){
				sum = sum + a[x];
			}
			subsum = sum % 100000007;
			if(subsum % k == 0) {
				count++;
			}
		}
		
	}

	printf("%d", count);
>>>>>>> Stashed changes
}