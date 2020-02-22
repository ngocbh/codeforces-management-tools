<<<<<<< Updated upstream
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int d;
    scanf("%d", &d);
    int n;
    scanf("%d", &n);
    int a[101][101] = {};
    for (int i = 1; i <= n; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        a[x][y] = w;
    }
    ll s[101][101] = {};
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i-1][j-1] + a[i][j];
        }
    }
    int x0 = 0, y0 = 0;
    ll sum = 0;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            int x_max = min(100, i + d);
            int y_max = min(100, j + d);
            int x_min = max(0, i - d - 1);
            int y_min = max(0, j - d - 1);
            ll t = s[x_max][y_max] - (s[x_max][y_min] + s[x_min][y_max] - s[x_min][y_min]);
            
            if(t > sum) {
                sum = t;
                x0 = i;
                y0 = j;
            }
        }
    }
    printf("%d %d %lld", x0, y0, sum);
    return 0;
=======
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int d;
    scanf("%d", &d);
    int n;
    scanf("%d", &n);
    int a[101][101] = {};
    for (int i = 1; i <= n; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        a[x][y] = w;
    }
    ll s[101][101] = {};
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i-1][j-1] + a[i][j];
        }
    }
    int x0 = 0, y0 = 0;
    ll sum = 0;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            int x_max = min(100, i + d);
            int y_max = min(100, j + d);
            int x_min = max(0, i - d - 1);
            int y_min = max(0, j - d - 1);
            ll t = s[x_max][y_max] - (s[x_max][y_min] + s[x_min][y_max] - s[x_min][y_min]);
            
            if(t > sum) {
                sum = t;
                x0 = i;
                y0 = j;
            }
        }
    }
    printf("%d %d %lld", x0, y0, sum);
    return 0;
>>>>>>> Stashed changes
}