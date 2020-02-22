<<<<<<< Updated upstream
#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;
 
ll d;
ll f[500][500];
int n;
 
main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> d >> n;
    while(n--){
        int x,y,c;
        cin >> x >> y >> c;
        f[x+100][y+100] += c;
    }
    n = 300;
    for(int i = 1; i <n; ++i)
    for(int j = 1; j < n; ++j)
    f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    ll res = 0,u = 0,v = 0;
    for(int i = 100; i <= 200; ++i)
    for(int j = 100; j <= 200; ++j){
        ll c = f[i+d][j+d] - f[i-d-1][j+d] - f[i+d][j-d-1] + f[i-d-1][j-d-1];
        if(c > res) res = c,u = i,v = j;
    }
    cout << u-100 << " " << v-100 << " " << res;
=======
#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;
 
ll d;
ll f[500][500];
int n;
 
main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> d >> n;
    while(n--){
        int x,y,c;
        cin >> x >> y >> c;
        f[x+100][y+100] += c;
    }
    n = 300;
    for(int i = 1; i <n; ++i)
    for(int j = 1; j < n; ++j)
    f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    ll res = 0,u = 0,v = 0;
    for(int i = 100; i <= 200; ++i)
    for(int j = 100; j <= 200; ++j){
        ll c = f[i+d][j+d] - f[i-d-1][j+d] - f[i+d][j-d-1] + f[i-d-1][j-d-1];
        if(c > res) res = c,u = i,v = j;
    }
    cout << u-100 << " " << v-100 << " " << res;
>>>>>>> Stashed changes
}