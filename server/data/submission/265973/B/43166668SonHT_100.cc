#include <iostream>
#include <math.h>
using namespace std;

int d, n, arr[110][110];
int x_best, y_best, max_sum;

bool check(int x, int y) {
    return x >= 0 && x <= 100 && y >= 0 && y <= 100;
}

int getSum(int x, int y) {
    int res = 0;
    for (int i = x - d; i <= x + d; i++) {
        for (int j = y - d; j <= y + d; j++) {
            if (check(i, j)) {
                res += arr[i][j];
            }
        }
    }
    return res;
}

void input() {
    cin >> d >> n;
    int x, y, c;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> c;
        arr[x][y] = c;
    }
}

int main()
{
    input();
    max_sum = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            int ans = getSum(i, j);
            if (ans > max_sum) {
                max_sum = ans;
                x_best = i;
                y_best = j;
            }
        }
    }

    cout << x_best << " " << y_best << " " << max_sum << endl;
}
