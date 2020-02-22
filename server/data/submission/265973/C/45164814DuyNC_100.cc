#include <bits/stdc++.h>


using namespace std;

int n;

// 1 4 15 56 209 780
int main() {
    cin >> n;
    long long u = 0;
    long long v = 1;
    long long ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = (v*4 - u + 1000000007ll) % 1000000007ll;
        u = v;
        v = ans;
    }
    cout << ans;;
}
