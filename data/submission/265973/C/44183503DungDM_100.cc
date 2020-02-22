#include <bits/stdc++.h>
using namespace std;

#define ff(i,a,b) for (int i = a; i <= b; i++)
#define fb(i,a,b) for (int i = a; i >= b; i--)
#define maxl 100007
#define div 1000000007
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, a[maxl];
    cin >> n;
    a[1] = 1;
    a[2] = 4;
    ff(i,3,n) {
        int x = (4 * a[i - 1]) % div;
        if (x < a[i - 2]) x += div;
        a[i] = (x - a[i - 2]) % div;
    }
    cout << a[n];
    return 0;

}