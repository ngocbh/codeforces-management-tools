#include<stdio.h>
#include<stdlib.h>
 
typedef unsigned long long ull;
 
int* T;
int* d;
int* pt;
int* sol;
int* doctorLoad;
 
int* cumSum;
int minPay;
 
void schedule(int* x, int n, int m, int k, ull curCost, ull* record){    
    if(k == n){
        if(*record == 0 || curCost < *record){
            for(int i = 0; i < n; i++){
                sol[i] = x[i];
                *record = curCost;
            }
        }
    }else{
        if((curCost >= *record || curCost + cumSum[k]*minPay >= *record) && *record > 0){
            return;
        }
        for(int i = 0; i < m; i++){
            int tmpMinPay = minPay;
            if(doctorLoad[i] + pt[k] <= T[i]){
                x[k] = i;
                doctorLoad[i] += pt[k];
                if(doctorLoad[i] == T[i] && minPay == d[i]){
                    tmpMinPay = minPay;
                    for(int j = 0; j < m; j++){
                        if(d[j] >= tmpMinPay && j != i && (d[j] < minPay || minPay == tmpMinPay)){
                            minPay = d[j];
                        }
                    }
                }
                schedule(x, n, m, k + 1, curCost + pt[k]*d[i], record);
                doctorLoad[i] -= pt[k];
                minPay = tmpMinPay;
            }
        }
    }
}
 
int main(int argc, char const *argv[]){
    // freopen("./data/E_test.txt", "r", stdin);
    int m, n;
    scanf("%d", &m);
    T = (int*)malloc(sizeof(int)*m);
    d = (int*)malloc(sizeof(int)*m);
 
    for(int i = 0; i < m; i++){
        scanf("%d", T + i);
    }
 
    minPay = -1;
    for(int i = 0; i < m; i++){
        scanf("%d", d + i);
        if(minPay == -1 || minPay > d[i]){
            minPay = d[i];
        }
    }
 
    scanf("%d", &n);
    pt = (int*)malloc(sizeof(int)*n);
    cumSum = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", pt + i);
    }
    cumSum[n - 1] = pt[n - 1];
    for(int i = n - 2; i >= 0; i--){
        cumSum[i] = cumSum[i + 1] + pt[i];
    }
    
    sol = (int*)calloc(n, sizeof(int));
    doctorLoad = (int*)calloc(n, sizeof(int));
    int* x = (int*)calloc(n, sizeof(int));
 
    ull record = 0;
    schedule(x, n, m, 0, 0, &record);
 
    if(record > 0){
        printf("%llu\n", record);
        int count[m];
        int ptlist[m][n];
        for(int i = 0; i < m; i++){
            count[i] = 0;
        }
        for(int i = 0; i < n; i++){
            int doctor = sol[i];
            ptlist[doctor][count[doctor]] = i;
            count[doctor]++;
        }
        for(int i = 0; i < m; i++){
            printf("%d ",count[i]);
            for(int j = 0; j < count[i]; j++){
                printf("%d ", ptlist[i][j] + 1);
            }
            printf("\n");
        }
    }
    else
        printf("-1\n");
 
    free(T);
    free(d);
    free(pt);
    free(sol);
    free(doctorLoad);
    free(x);
    free(cumSum);
    return 0;
}