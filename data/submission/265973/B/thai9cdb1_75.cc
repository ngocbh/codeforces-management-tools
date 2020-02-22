#include<bits/stdc++.h>
using namespace std;

main(){
    int d;
    cin >> d;
    int n;
    cin >> n;
    set<pair<int,int>> S;
    map<pair<int,int>, int> M;
    while(n--){
        int x, y, z;
        cin >> x >> y >> z;
        assert(x >= 1 && x <= 100 && y >= 1 && y <= 100 && !S.count({x, y}));
        S.insert({x, y});
        M[{x, y}] = z;
    }
    int ans = 0, x, y;
    for (int i = 1; i <= 100; ++i) for (int j = 1; j <= 100; ++j){
        int cnt = 0;
        for (auto A : S) if (max(abs(A.first-i), abs(A.second-j)) <= d) {
            cnt += M[A];
        }
        if (cnt > ans) ans = cnt, x = i, y = j;
    }
    cout << x << " " << y << " " << ans;
}
