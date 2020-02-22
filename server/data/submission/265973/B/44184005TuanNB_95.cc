#include <bits/stdc++.h>
#define num 100
using namespace std;
long long int a[1000][1000],f[1000][1000];
long n,d;
void compute(long x,long y)
{
    long long int i,j,k,tong,r0,r1,c0,c1;
    tong=0;
    k=min(min(x-1,y-1),d);
    r0=x-k;
    c0=y-k;
    k=min(min(num-x,num-y),d);
    r1=x+k;
    c1=y+k;
    for (i=r0;i<=r1;i++)
    for (j=c0;j<=c1;j++)
    {
        tong=tong+a[i][j];
    }
    f[x][y]=tong;
}
void enter()
{
    long i,j,x,y;
    cin>>d;
    for (i=1;i<=num;i++)
    for (j=1;j<=num;j++) a[i][j]=0;
    cin>>n;
    for (i=1;i<=n;i++) 
    {
        cin>>x>>y>>j;
        a[x][y]=j;
    }
}
void process()
{
    long long int  i,j,maxi,nhox,nhoy;
    maxi=0;
    for (i=1;i<=num;i++)
    for (j=1;j<=num;j++) compute(i,j);
    for (i=1;i<=num;i++)
    for (j=1;j<=num;j++) if (f[i][j]>maxi)
    {
        maxi=f[i][j];
        nhox=i;
        nhoy=j;
    }
    cout<<nhox<<" "<<nhoy<<" "<<maxi;
}
int main()
{
    enter();
    process();
}