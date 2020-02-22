#include <iostream>
#define MAXN 10005
using namespace std;
 
int d,n;
int matrix[102][102];
int res[3];

int check (int x, int y) {
    int boom = 0;
    for (int i = x-d; i<=x+d; i++) {
        for (int j = y-d; j<=y+d; j++) {
            if (i>=0 && i<=100 && j >=0 && j <=100) {
                boom += matrix[i][j];;
            }
        }
    }
    return boom;
}
 
void Solve(){
    res[2] = -1;
    for (int i = 0; i<=100; i++) {
        for (int j = 0; j<=100; j++) {
            int k = check(i, j);
            if (k > res[2]) {
                res[2] = k;
                res[1] = j;
                res[0] = i;
            }
        }
    }
    
    cout << res[0] << " " << res[1] << " " << res[2];
}
    
 
void Input(){
    cin >> d >> n;
    for (int i = 1; i<=n; i++) {
        int x,y,chuot;
        cin >> x >> y >> chuot;
        matrix[x][y] = chuot;
    }
}
 
int main(){
    Input();
    Solve();
    
    return 0;
}
