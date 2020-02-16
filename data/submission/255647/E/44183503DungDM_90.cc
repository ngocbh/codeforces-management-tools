#include <bits/stdc++.h>

#define MAX_INT 2000000000
#define ff(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

typedef long long ll;

//t: tg của bệnh nhân, td: tg bác sĩ, dg: đơn giá, dcs
int t[20], td[20], dg[20], dcs[20] = {0}, d[20][20], dbest[20][20], dcsbest[20];
int m, n, sum = 0, minn = MAX_INT;
int mindg=MAX_INT, mintg=MAX_INT;

void Try(int k) {
    ff(i, 1, m) {
        if (t[k] <= td[i]) {
            sum += t[k] * dg[i];
            dcs[i]++; 
            d[i][dcs[i]] = k;
            td[i] -= t[k];
            if (k == n) {
                if (sum < minn) {
                    minn = sum;
                    ff(x, 1, m)
                        ff(y, 1, dcs[x]) 
                            dbest[x][y] = d[x][y];
                    ff(x, 1, n) dcsbest[x] = dcs[x];
                }
            }
            else {
                if (sum + mindg * mintg * (n - k) < minn)
                    Try(k + 1);
            }
            td[i] += t[k];
            dcs[i]--;
            sum -= t[k] * dg[i];
        }
    }
}

int main() {
    cin >> m;
    ff(i, 1, m) cin >> td[i];
    ff(i, 1, m) {cin >> dg[i]; if (mindg > dg[i]) mindg =dg[i];}
    cin >> n;
    ff(i, 1, n) {cin >> t[i]; if (mintg > t[i]) mintg = t[i];}
    Try(1);
    if (minn == MAX_INT) {cout << -1; return 0;}
    cout << minn << endl;
    ff(i, 1, m) {
        cout << dcsbest[i] << " ";
        ff(j, 1, dcsbest[i]) cout << dbest[i][j] << " "; 
        cout << endl;
    }
    return 0;
}