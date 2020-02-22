#include <bits/stdc++.h>

using namespace std;

int n, d, x, y, c, ansX, ansY;
long long a[102][102], ans;

int main() {
//    freopen("inp.txt", "r", stdin);
    cin >> d >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> c;
        a[x][y] += c;
    }
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            int minX = max(0, i - d - 1);
            int minY = max(0, j - d - 1);
            int maxX = min(100, i + d);
            int maxY = min(100, j + d);
            long long foo = a[maxX][maxY] - a[minX][maxY] - a[maxX][minY] + a[minX][minY];
            if (ans < foo) {
                ansX = i;
                ansY = j;
                ans = foo;
            }
        }
    }
    cout << ansX << ' ' << ansY << ' ' << ans;
}
