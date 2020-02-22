#include <bits/stdc++.h>
using namespace std;
long s[10001][10001];
long a[10001];
long n,k;
void enter()
{
    long i;
    cin>>n>>k;
    for (i=1;i<=n;i++) cin>>a[i];
}
void process()
{
    long i,j,dem;
    dem=0;
    for (i=1;i<=n;i++) s[i][i]=a[i];
    for (i=1;i<=n-1;i++)
    for (j=1;j<=n-i;j++) s[j][j+i]=s[j][j+i-1]+a[j+i];
    for (i=1;i<=n;i++)
    for (j=i;j<=n;j++) if (s[i][j]%k==0) dem++;
    cout<<dem;
}
int main()
{
    enter();
    process();
}