#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull;

ull* customer;
ull* worker;

ull computeCost(int w, int c){
    ull tmp = (customer[c] - worker[w]);
    return tmp*tmp;
}

int compare(const void* x, const void* y){
    int a = *((int*) x);
    int b = *((int*) y);
    if(a > b)   return 1;
    if(a == b)  return 0;
    return -1;
}

int rcompare(const void* x, const void* y){
    int a = *((int*) x);
    int b = *((int*) y);
    if(a > b)   return -1;
    if(a == b)  return 0;
    return 1;
}

int main(int argc, char const *argv[]){
    // freopen("./data/C_test.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    worker = (ull*)malloc(sizeof(ull)*n);
    customer = (ull*)malloc(sizeof(ull)*n);
    for(int i = 0; i < n; i++){
        scanf("%llu", worker + i);
    }
    for (int i = 0; i < n; i++){
        scanf("%llu", customer + i);
    }
    qsort(worker, n, sizeof(ull), compare);
    qsort(customer, n, sizeof(ull), compare);
    ull result = 0;

    for(int i = 0; i < n; i++){
        result += computeCost(i, i);
    }
    printf("%llu\n", result);
    return 0;
}
