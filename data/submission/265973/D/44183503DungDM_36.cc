#include <bits/stdc++.h>
using namespace std;

#define ff(i,a,b) for (int i = a; i <= b; i++)
#define fb(i,a,b) for (int i = a; i >= b; i--)
#define maxl 100007
#define maxint 1000000007
#define st first
#define nd second

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

int n, m, x, y, k, minn = maxint;
iii a[maxl];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ff(i,1,m) {
        cin >> x >> y >> k;
        a[i] = iii(ii(x,y), k);
        if (k != -1 && k < minn) 
            minn = k;
    }
    cout << minn;
    return 0;
}