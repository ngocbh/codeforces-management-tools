#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    int sum[10005];
    int res =0;
    cin >> n >> k;
    for (int i=1; i<=n; ++i)
    {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    for (int i=0; i<n; ++i)
    {
        for (int j=i+1; j<=n ; ++j)
            if ((sum[j]-sum[i]) % k == 0) res++;

    }
    cout << res;
    return 0;
}
