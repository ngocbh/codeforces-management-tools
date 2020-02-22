#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;

int dis(int p, int q) {
    int t = p - q;
    return t*t;
}

int main() {
	int n;
    ll tho[n], kh[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &tho[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &kh[i]);
    }
    
    sort(tho, tho + n);
    sort(kh, kh + n);
    ll res = 0;
    for(int i = 0; i < n; i++) {
        res += dis(kh[i], tho[i]);
    }
    cout << res;
	return 0;
}