<<<<<<< Updated upstream
#include <bits/stdc++.h>
#define Speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define st              first
#define nd              second
#define pb              push_back
#define pf              push_front
#define all(a)          (a).begin(), (a).end()
#define lwb             lower_bound
#define upb             upper_bound
#define vvll            vector<vector<ll> >
#define Mset(s, n)      memset(s, n, sizeof(s))
#define Sz(a)           int((a).size())
#define Max(a, b, c)    max(max((ll)(a), (ll)(b)), (ll)(c))
#define Min(a, b, c)    min(min((ll)(a), (ll)(b)), (ll)(c))
#define Unique(a)       sort(all(a)); (a).resize(unique(all(a)) - (a).begin())

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const int oo = 2e9;
const ld PI = acos((ld) -1);
int Getbit(ll x, int k){return (x >> (k - 1)) & 1;}
ll Lcm(ll a, ll b) {return a / __gcd(a, b) * b;}
bool isPrime(ll n){for(ll i = 2; i * i <= n; i++){if(n % i == 0) return 0;} return (n > 1) ? 1 : 0;}
ll Powmod(ll n, ll k, ll p = MOD) {ll r = 1; for(; k; k /= 2, n = n * n % p){if(k & 1) r = r * n % p;} return r;}

const int N = 2e5 + 5;

ll n, m, k;
ll a[N];
ll f[3][10004];

void Solve(){
    ll res = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        f[2][a[i] % k] = 1;
        for(int j = 0; j < k; j++){
            f[2][(a[i] + j) % k] += f[1][j];
        }
        res += f[2][0];
        for(int j = 0; j < k; j++){
            f[1][j] = f[2][j];
            f[2][j] = 0;
        }
    }
    cout << res;
}

int main(){
    Speed;
    int query = 1;
//    cin >> query;
    while(query--) Solve();
}







=======
#include <bits/stdc++.h>
#define Speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define st              first
#define nd              second
#define pb              push_back
#define pf              push_front
#define all(a)          (a).begin(), (a).end()
#define lwb             lower_bound
#define upb             upper_bound
#define vvll            vector<vector<ll> >
#define Mset(s, n)      memset(s, n, sizeof(s))
#define Sz(a)           int((a).size())
#define Max(a, b, c)    max(max((ll)(a), (ll)(b)), (ll)(c))
#define Min(a, b, c)    min(min((ll)(a), (ll)(b)), (ll)(c))
#define Unique(a)       sort(all(a)); (a).resize(unique(all(a)) - (a).begin())

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const int oo = 2e9;
const ld PI = acos((ld) -1);
int Getbit(ll x, int k){return (x >> (k - 1)) & 1;}
ll Lcm(ll a, ll b) {return a / __gcd(a, b) * b;}
bool isPrime(ll n){for(ll i = 2; i * i <= n; i++){if(n % i == 0) return 0;} return (n > 1) ? 1 : 0;}
ll Powmod(ll n, ll k, ll p = MOD) {ll r = 1; for(; k; k /= 2, n = n * n % p){if(k & 1) r = r * n % p;} return r;}

const int N = 2e5 + 5;

ll n, m, k;
ll a[N];
ll f[3][10004];

void Solve(){
    ll res = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        f[2][a[i] % k] = 1;
        for(int j = 0; j < k; j++){
            f[2][(a[i] + j) % k] += f[1][j];
        }
        res += f[2][0];
        for(int j = 0; j < k; j++){
            f[1][j] = f[2][j];
            f[2][j] = 0;
        }
    }
    cout << res;
}

int main(){
    Speed;
    int query = 1;
//    cin >> query;
    while(query--) Solve();
}







>>>>>>> Stashed changes
