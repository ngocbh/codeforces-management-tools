#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int d;
int n;
int ** A;

int x_0 = 0, y_0 = 0, max_die = 0;

void input(){
    cin >> d >> n;

    A = new int*[101];
    for(int i = 0 ; i < 101 ; i ++){
        A[i] = new int[101];
        fill(A[i], A[i] + 101, 0);
    }

    int x, y, c;
    for(int i = 0 ; i < n ; i ++){
        cin >> x >> y >> c;
        A[x][y] = c;
    }
}

ll checksum(int x, int y){
    ll s = 0;
    for(int i = max(x - d, 0) ; i <= min(x + d, 101 - 1) ; i ++){
        for(int j = max(y - d, 0) ; j <= min(y + d, 101 - 1) ; j ++){
            s += A[i][j];
        }
    }

    return s;
}

void go(){
    for(int i = 0 ; i < 101 ; i ++){
        for(int j = 0 ; j < 101 ; j ++){
            ll s = checksum(i, j);
            if(s > max_die){
                max_die = s;
                x_0 = i; 
                y_0 = j;
            }
        }
    }

    cout << x_0 << " " << y_0 << " " << max_die;
}

int main(){
    input();
    go();
    return 0;
}