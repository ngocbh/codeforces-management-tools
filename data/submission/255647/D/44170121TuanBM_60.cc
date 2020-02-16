#include<bits/stdc++.h>
using namespace std;
#define Fr(i,a,b) for(int i=a;i<=b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
const int oo=INT_MAX;
const int N=18;
const int M=9;
ll n;

int Get(int x)
{
    int y=x-1;
    int m=0,a[10];
    while(x)
    {
        if(m==0 || a[m]!=(x%10)) a[++m]=x%10;
        x/=10;
    }
    while(a[m]==y%10) m--;
    return m;
}

void bruteForces()
{
    ll cnt=0;
    Fr(i,1,10000000)
    {
        int x=Get(i);
        if(cnt+x>=n)
        {
            printf("%d",i);
            break;
        }
        cnt+=x;
    }
}

int main()
{
    scanf("%lld",&n);
    if(n<=10000000) bruteForces();
    return 0;
}

