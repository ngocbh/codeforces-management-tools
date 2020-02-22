#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Max 100


int d;
int n;
int c[Max +1][Max +1];
int f_best[3];
int f[3];
int min_x = 1000000;
int max_x = -1000000;
int min_y = 1000000;
int max_y = -1000000;

int appear[Max + 1][Max + 1];

void input(){
    scanf("%d", &d);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &c[i][j]);
        }
    }
}
// void show(){
//     printf("\n");
//     for(int i = 0; i < 3; i++){
//         printf("%d ", f[i]);
//     }
// }
int check(int v,int k){
    if((v > max_y)||(k > max_x)){
        return 0;
    }
    for(int i = 0; i < n ; i++){
        int disx = abs(c[i][0] - k);
        int disy = abs(c[i][1] - v);
        int dis = disx > disy ? disx : disy;
        if(dis <= d){
            return 1;
        }
    }
    return 0;
}
void solution(){
    if(f_best[2] < f[2]){
        for(int i = 0; i < 3;i++){
            f_best[i] = f[i];
        }
    }    
}
void TRY(int k){
    f[2] = 0;
    f[0] = 0;
    f[1] = 0;
    for(int v = min_y; v <= max_y; v++){
        // printf("\n%d %d \n", k, v);
        if(check(v,k)){
            for(int i = 0; i < n ; i++){
                int disx = abs(c[i][0] - k);
                int disy = abs(c[i][1] - v);
                int dis = disx > disy ? disx : disy;
                if(dis <= d){
                    f[2] += c[i][2];
                }
            }
            f[0] = k;
            f[1] = v;
            solution();      
            f[2] = 0;
            f[0] = 0;
            f[1] = 0;
        }
        if(k == max_x){
            break;
        }
        else{
            if(f[2] < f_best[2]){
                TRY(k + 1);
            }
        } 
    }
}
void solve(){
    f[2] = 0;
    f_best[2] = -100000;
    TRY(min_x);
    for(int i = 0; i < 3; i++){
        printf("%d ", f_best[i]);
    }
}
int main(){
    input();
    for(int i = 0; i < n; i++){
        min_x = min_x < c[i][0] ? min_x : c[i][0];
        max_x = max_x > c[i][0] ? max_x : c[i][0];
        min_y = min_y < c[i][1] ? min_y : c[i][1];
        max_y = max_y > c[i][1] ? max_y : c[i][1];
    }
    solve();
    return 0;
}
