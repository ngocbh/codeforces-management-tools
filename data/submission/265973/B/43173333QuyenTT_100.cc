#include<bits/stdc++.h>
#define MAX 102
using namespace std;
int n, d, a[MAX][MAX];
int minX, minY, maxX, maxY;

void input(){
    cin >> d >> n;
    for(int i = 1; i<=100; i++){
        for(int j = 1; j<=100; j++)
            a[i][j] = 0;
    }

    minX = minY =100;
    maxX = maxY = 1;
    int x, y, s;
    for(int i = 1; i<=n; i++){
        cin >> x >> y >> s;
        a[x][y] = s;
        if(x > maxX) maxX = x;
        if(x < minX) minX = x;
        if(y > maxY) maxY = y;
        if(y < minY) minY = y;
    }

    //cout << minX << " " << minY << " " << maxX << " " << maxY << endl;
}

int Kill(int x, int y, int d){
    int mminX, mminY, mmaxX, mmaxY;
    if(x - d >1) mminX = x-d;
    else mminX = 1;
    if(x + d <100) mmaxX = x+d;
    else mmaxX = 100;

    if(y - d >1) mminY = y-d;
    else mminY = 1;
    if(y + d <100) mmaxY = y+d;
    else mmaxY = 100;

    //cout <<"----";
    //cout << "\n Giet tai " << x << ", " <<y << ": ";
    //cout << minX << " " << minY << " " << maxX << " " << maxY << endl;

    int sum = 0;
    for(int i = mminX; i<=mmaxX; i++){
        for(int j = mminY; j<=mmaxY; j++){
            sum +=a[i][j];
        }
    }
    //cout << sum;
    return sum;
}

void solve(){
    int ans = 0;
    int ansX = 1, ansY = 1;
    int delta; // so chuot;

    for(int x = minX; x<=maxX; x++){
        for(int y = minY; y<=maxY; y++){
            delta = Kill(x, y, d);
            if(ans < delta){
                ans = delta;
                ansX = x; ansY = y;
            }
        }
    }

    cout << ansX << " " << ansY << " " << ans;
}

int main(){
    input();
    solve();
}
