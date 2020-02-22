<<<<<<< Updated upstream
#include <stdio.h>
#include <conio.h>

int main() {
	int n, i, j, k, sum, count = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	int a[n];
	for( i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i]%k == 0) count++;
	}	
	
	for( i = 0; i < n; i++){
		sum = a[i];
		for( j = i+1; j < n; j++){
			sum = sum + a[j];
			if(sum % k == 0) {
				count++;
			}
		}
		
	}

	printf("%d", count);
=======
#include <stdio.h>
#include <conio.h>

int main() {
	int n, i, j, k, sum, count = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	int a[n];
	for( i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i]%k == 0) count++;
	}	
	
	for( i = 0; i < n; i++){
		sum = a[i];
		for( j = i+1; j < n; j++){
			sum = sum + a[j];
			if(sum % k == 0) {
				count++;
			}
		}
		
	}

	printf("%d", count);
>>>>>>> Stashed changes
}