#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Max 100

int n;
int k;
int arr[Max + 1]; 
void input(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}
void solution(){
    int count = 0;
    for(int i = 0; i< n; i++){
        int tong = 0;
        for(int j = i; j < n; j++){
            tong += arr[j];
            if (tong % k == 0){
                count ++;
            }
        }
    }
    printf("%d", count);
}
int main(){
    input();
    solution();
    return 0;
}