<<<<<<< Updated upstream
#include<bits/stdc++.h>
using namespace std;

int d, n, m[101][101] = {};
int bx, by, ba = 0;

int main(){
    cin >> d >> n;
    for(int i = 1; i <= n; i++){
        int x, y, a;
        cin >> x >> y >> a;
        m[x][y] = a;
    }
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            int a = 0;
            for(int k1 = -d; k1 <= d; k1++){
                if(i + k1 > 0 && i + k1 <= 100){
                    for(int k2 = -d; k2 <= d; k2++){
                        if(j + k2 > 0 && j + k2 <= 100){
                            a += m[i + k1][j + k2];
                        }
                    }
                }
            }
            if(a > ba){
                ba = a;
                bx = i;
                by = j;
            }
            else if(a == ba){
                if(bx > i){
                    bx = i;
                    by = j;
                }
                else if(bx == i && by > j){
                    bx = i;
                    by = j;
                }
            }
        }
    }
    cout << bx << " " << by << " " << ba << endl;
}
=======
#include<bits/stdc++.h>
using namespace std;

int d, n, m[101][101] = {};
int bx, by, ba = 0;

int main(){
    cin >> d >> n;
    for(int i = 1; i <= n; i++){
        int x, y, a;
        cin >> x >> y >> a;
        m[x][y] = a;
    }
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            int a = 0;
            for(int k1 = -d; k1 <= d; k1++){
                if(i + k1 > 0 && i + k1 <= 100){
                    for(int k2 = -d; k2 <= d; k2++){
                        if(j + k2 > 0 && j + k2 <= 100){
                            a += m[i + k1][j + k2];
                        }
                    }
                }
            }
            if(a > ba){
                ba = a;
                bx = i;
                by = j;
            }
            else if(a == ba){
                if(bx > i){
                    bx = i;
                    by = j;
                }
                else if(bx == i && by > j){
                    bx = i;
                    by = j;
                }
            }
        }
    }
    cout << bx << " " << by << " " << ba << endl;
}
>>>>>>> Stashed changes
