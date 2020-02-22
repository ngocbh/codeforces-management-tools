#include<stdio.h>

int BIG_NUMBER = 1000000007;

int f(int a){
    if(a == 0){
        return 1;
    }else{
        if(a%2 == 1){
            int tmp = f(a/2);
            tmp = (tmp*tmp)%BIG_NUMBER;
            return (tmp*3)%BIG_NUMBER;
        }else{
            int tmp = f(a/2);
            tmp = (tmp*tmp)%BIG_NUMBER;
            return tmp;
        }
    }
}

int main(int argc, char const *argv[]){
    // freopen("./data/C_test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int result = f(n - 2);
    result = (result*4)%BIG_NUMBER;
    printf("%d\n", result);
    return 0;
}
