#include <bits/stdc++.h>
#define q 1000000007
using namespace std;
long long int f[1000001];
int main()
{
    long n,i,j;
    cin>>n;
    f[1]=1;
    f[2]=4;
    for (i=3;i<=n;i++) f[i]=(4*f[i-1]-f[i-2])%q;
    if (f[n]<0) cout<<f[n]+q;
    else cout<<f[n];
}
