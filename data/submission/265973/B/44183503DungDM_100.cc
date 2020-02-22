#include <bits/stdc++.h>
using namespace std;

#define ff(i,a,b) for (int i = a; i <= b; i++)
#define fb(i,a,b) for (int i = a; i >= b; i--)
#define maxl 20007
#define st first
#define nd second

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

int d, n, x, y, c;
int maxx = 0, maxy = 0, kill = 0, sx, sy, maxkill = 0;
iii a[maxl];
vector<int> ax, ay;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> d >> n;
    ff(i,1,n) {
        cin >> x >> y >> c;
        a[i] = iii(ii(x, y), c);
    }
    
    ff(i,1,100)
        ff(j,1,100) {
            kill = 0;
            ff(k, 1, n) {
                if (max(abs(i - a[k].st.st), abs(j - a[k].st.nd)) <= d)
                    kill += a[k].nd;
            }
            if (kill > maxkill) {
                maxkill = kill;
                sx = i;
                sy = j;
            }
        }

    cout << sx << " " << sy << " " << maxkill;
    return 0;

}