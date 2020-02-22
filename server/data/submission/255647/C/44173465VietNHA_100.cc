#include <bits/stdc++.h>

using namespace std;

long long n, tho[30001], kh[30001];
long long sum = 0;

int main()
{
    //in: solution
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> tho[i];
    for (int i = 1; i <= n; i++) cin >> kh[i];
    sort(tho+1, tho+1+n);
    sort(kh+1, kh+1+n);

    for (int i = 1; i <= n; i++) sum+= (tho[i] - kh[i]) * (tho[i] - kh[i]);
    cout << sum;
    return 0;
}
