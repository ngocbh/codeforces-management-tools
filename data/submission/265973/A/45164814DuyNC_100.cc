#include <bits/stdc++.h>

using namespace std;

int n, k, a[10004];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((a[j] - a[i]) % k == 0) {
                ++ans;
            }
        }
    }
    cout << ans;
}
