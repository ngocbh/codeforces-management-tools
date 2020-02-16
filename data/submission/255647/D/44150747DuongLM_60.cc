#include<stdio.h>

typedef unsigned long long ull;

ull countUnique(ull x){
    ull c = 1;
    int prev = x%10;
    int cur;
    x = x/10;
    while(x > 0){
        cur = x%10;
        if(cur != prev){
            c++;
            prev = cur;
        }
        x = x/10;
    }
    return c;
}

int main(int argc, char const *argv[]){
    ull s;
    scanf("%llu", &s);
    ull count = 0;
    ull i = 1;
    int finalDigit = 0;
    ull mulFactor = 10;
    while(count < s){
        if(i >= mulFactor){
            mulFactor *= 10;
        }
        int tmp = finalDigit;
        
        ull tmp1 = countUnique(tmp*mulFactor + i);
        count += tmp1;
        if(finalDigit > 0){
            count--;
        }       

        finalDigit = i%10;
        // printf("%llu %llu\n", i, count);
        i++;
        
    }
    printf("%llu\n", i - 1);
    return 0;
}
