#include <bits/stdc++.h>

using namespace std;
int m, n;
int gio[8], gia[8];
int benhnhan[17];
//more
int bacsi[8]; //bacsi i dang kham duoc ngan nay gio
bool check[8][17]; //xem bac si i co kham benh nhan j hay khong
long long chiphi = 9000000000000l ; //toiuu
long long now[17]; //chi phi cho toi benh nhan i
bool kq = false;
bool luu[8][17];
int dem[8];

void tim(int i) {
    for (int j = 1; j <= m; j++ ) {
        if (bacsi[j] + benhnhan[i] <= gio[j]) {
            now[i] = now[i-1] + benhnhan[i]*gia[j];
            if (now[i] < chiphi) {
                check[j][i] = true;
                bacsi[j] += benhnhan[i];
                if (i == n) {
                    kq = true;
                    chiphi = now[i];
                    for (int k = 1; k <= m; k++) {
                        for (int a = 1; a <= n; a++) {
                            if (check[k][a]) { // bac si k kham benh nhan n;
                                luu[k][a] = true;
                                dem[k]++;
                            }
                            else luu[k][a] = false;
                        }
                    }
                }
                else tim(i+1);
                check[j][i] = false;
                bacsi[j] -= benhnhan[i];
            }
        }
    }
}

int main() {
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> gio[i];
    for (int i = 1; i <= m; i++) { cin >> gia[i]; bacsi[i] = 0;}
    for (int i = 1; i <= m; i++) {
        dem[i] = 0;
        for (int j = 1; j <= n; j++) {
            check[i][j] = false;
            luu[i][j] = false;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> benhnhan[i];
    now[0] = 0;
    tim(1);
    if (kq) {
        cout << chiphi << "\n";
        for (int i = 1; i <= m; i++) {
            cout << dem[i] << " ";
            for (int j = 1; j <= n; j++) {
                if (luu[i][j]) cout << j << " ";
            }
        }
    }
    else cout << -1;
    return 0;
}
