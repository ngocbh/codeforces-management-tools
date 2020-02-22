#include <bits/stdc++.h>
using namespace std;

#define ff(i,a,b) for (int i = a; i <= b; i++)
#define fb(i,a,b) for (int i = a; i >= b; i--)
#define maxl 10007

int n, k, a[maxl], cnt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    ff(i,1,n) cin >> a[i];
    ff(i,1,n) {
        int sum = 0;
        ff(j, i, n) {
            sum += a[j];
            if (sum % k == 0) 
                cnt ++;
        }
    }
    cout << cnt;
    return 0;

}