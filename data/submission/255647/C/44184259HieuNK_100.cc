#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

const int N = 3e4 + 100;
int n;
ll a[N],b[N];


main(){
    //freopen(".inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; cin >> a[i++]);
    for(int i = 1; i <= n; cin >> b[i++]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ll res = 0;
    for(int i = 1; i <= n; ++i)
        res += (a[i] - b[i])*(a[i]-b[i]);
    cout << res;
}
