#include <bits/stdc++.h>

#define MAX_INT 2000000000
#define ff(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

typedef long long ll;

ll a[30000], b[30000];

int main() {
    ll n, s = 0; cin >> n;
    ff(i, 0, n-1) cin >> a[i];
    ff(i, 0, n-1) cin >> b[i];
    sort(a, a+n); sort(b,b+n);
    ff(i, 0, n-1) s+=(a[i]-b[i])*(a[i]-b[i]);
    cout << s;
    return 0;
}