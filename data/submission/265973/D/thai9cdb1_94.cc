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

const int N = 1e5 + 5;

ll n, m, k;
ll a[N];

map<pii, int> mp;

struct Point{
    int x, y, w;
};
int root[N], sz[N], par[N];
vector<int> s[N];

int find_root(int x) {
    return x == root[x] ? x : root[x] = find_root(root[x]);
}

bool unite(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x == y)
        return false;

    if (sz[x] < sz[y])
        swap(x, y);
    for(int v: s[y]){
        s[x].pb(v);
    }
    s[y].clear();
    root[y] = x;
    sz[x] += sz[y];
    return true;
}

bool check(int u, int v){
    int X = find_root(u);
    int Y = find_root(v);
    if(X == Y) return 1;
    for(int x: s[X]){
        for(int y: s[Y]){
            if(mp.count({x, y})) return 0;
        }
    }
    return true;
}

void Solve(){
    cin >> n >> m;
    vector<Point> p;
    int D = 0;
    for(int i = 1; i <= m; i++){
        int x, y, w;
        if(x > y) swap(x, y);
        cin >> x >> y >> w;
        if(w != -1){
            p.pb({x, y, w});
            D++;
        } else{
            mp[{x, y}] = 1;
            mp[{y, x}] = 1;
        }
    }
    sort(all(p), [](Point x, Point y){
        return x.w > y.w;
    });
    for(int i = 1; i <= n; i++){
        root[i] = i;
        sz[i] = 1;
        s[i].pb(i);
    }
    for(auto P: p){
        int x = P.x;
        int y = P.y;
        int w = P.w;
        if(check(x, y)){
            unite(x, y);
        } else{
            cout << w;
            return;
        }
    }
    cout << 0;
}

int main(){
    Speed;
    int query = 1;
//    cin >> query;
    while(query--) Solve();
}

/*
9 16
1 2 10
2 5 9
3 5 9
2 3 10
2 9 4
9 1 -1
4 6 12
4 3 8
3 6 6
6 2 -1
6 8 5
7 8 9
3 8 8
4 7 -1
7 1 -1
4 5 -1
*/
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

const int N = 1e5 + 5;

ll n, m, k;
ll a[N];

map<pii, int> mp;

struct Point{
    int x, y, w;
};
int root[N], sz[N], par[N];
vector<int> s[N];

int find_root(int x) {
    return x == root[x] ? x : root[x] = find_root(root[x]);
}

bool unite(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x == y)
        return false;

    if (sz[x] < sz[y])
        swap(x, y);
    for(int v: s[y]){
        s[x].pb(v);
    }
    s[y].clear();
    root[y] = x;
    sz[x] += sz[y];
    return true;
}

bool check(int u, int v){
    int X = find_root(u);
    int Y = find_root(v);
    if(X == Y) return 1;
    for(int x: s[X]){
        for(int y: s[Y]){
            if(mp.count({x, y})) return 0;
        }
    }
    return true;
}

void Solve(){
    cin >> n >> m;
    vector<Point> p;
    int D = 0;
    for(int i = 1; i <= m; i++){
        int x, y, w;
        if(x > y) swap(x, y);
        cin >> x >> y >> w;
        if(w != -1){
            p.pb({x, y, w});
            D++;
        } else{
            mp[{x, y}] = 1;
            mp[{y, x}] = 1;
        }
    }
    sort(all(p), [](Point x, Point y){
        return x.w > y.w;
    });
    for(int i = 1; i <= n; i++){
        root[i] = i;
        sz[i] = 1;
        s[i].pb(i);
    }
    for(auto P: p){
        int x = P.x;
        int y = P.y;
        int w = P.w;
        if(check(x, y)){
            unite(x, y);
        } else{
            cout << w;
            return;
        }
    }
    cout << 0;
}

int main(){
    Speed;
    int query = 1;
//    cin >> query;
    while(query--) Solve();
}

/*
9 16
1 2 10
2 5 9
3 5 9
2 3 10
2 9 4
9 1 -1
4 6 12
4 3 8
3 6 6
6 2 -1
6 8 5
7 8 9
3 8 8
4 7 -1
7 1 -1
4 5 -1
*/
>>>>>>> Stashed changes
