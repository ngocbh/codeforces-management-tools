#include<bits/stdc++.h>
using namespace std;
#define dembit1(x) __builtin_popcountll(x)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
const int mod=1e9+7;
const int oo = 0x3f3f3f3f;
const int N = 10001, K = 10001;
int a[N];
int s[N];
int n, k;
int Q = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        //cout << s[i];
    }
    for (int i = 0; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            //cout << s[i] << " " << s[j] << "\n";
            if ( ((s[j] - s[i]) % k)  == 0 ) ++Q;
        }
    }
    cout << Q;
    return 0;
}
