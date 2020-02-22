#include<bits/stdc++.h>
#define N 1000

using namespace std;

int n, m;
int A[N][N];

int max_c = 0;

void input(){
    cin >> n >> m;
    int x, y, k;

    for(int i = 0 ; i < N ; i ++){
        fill(A[i], A[i] + N, -1);
    }
    for(int i = 0 ; i < m ; i ++){
        cin >> x >> y >> k;
        A[x][y] = k;
    }
}

void go(){
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            if(A[i][j] > 0){
                for(int o = 0 ; o < n ; o ++){
                    if(A[j][o] > 0){
                        if(A[i][o] < 0){
                            max_c = max(max_c, min(A[i][j], A[j][o]));
                        }
                    }
                }
            }
        }
    }

    cout << max_c;
}

int main(){
    input();
    go();
    return 0;
}