#include<stdio.h>

int main(int argc, char const *argv[]){
    // freopen("./data/A_test.txt", "r", stdina);
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        int sum = arr[i];
        if(sum%k == 0){
            result++;
        }
        for(int j = i + 1; j < n; j++){
            sum += arr[j];
            if(sum%k == 0){
                result++;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
