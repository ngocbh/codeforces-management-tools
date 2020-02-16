#include <bits/stdc++.h>

#define MAX_INT 2000000000
#define maxa 1000000
#define ff(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

typedef long long ll;

ll a[maxa], b[maxa];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, state = -1, count = 0, maxval = 0, maxhil = 0; 
    cin >> n;
    ff(i, 0, n-1) cin >> a[i];
    ll j = 0; 
    if (a[1] > a[0]) {state=1; count=1;}
    else if (a[1] < a[0]) {state=-1; count=-1;} 
    else state=0;
    ff(i, 2, n-1) {
        if (a[i] == a[i-1]) {
            if (state != 0) { b[j] = count; j++; state=0; }
        }
        else if (a[i] > a[i-1]) {
            if (state == 1) {count++; continue;}
            if (state == 0) b[j] = 0; else b[j] = count;
            j++; count=1; state=1;
        }
        else if (a[i] < a[i-1]) {
            if (state == -1) {count--; continue;}
            if (state == 0) b[j] = 0; else b[j] = count; 
            j++; count=-1; state=-1;
        }
    }
    if (count != 0) b[j] = count;
    // ff(k, 0, j) cout << b[k] << " ";
    ff(k, 1, j) {
        ll temp = min(abs(b[k-1]), abs(b[k]));
        if (b[k-1] < 0 && b[k] > 0 && maxval < temp) maxval = temp;
        else if (b[k-1] > 0 && b[k] < 0 && maxhil < temp) maxhil = temp;
    }
    // cout << endl;
    cout << maxhil << " " << maxval;
    return 0;
}