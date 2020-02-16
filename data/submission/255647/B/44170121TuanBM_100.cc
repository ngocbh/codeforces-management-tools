#include<bits/stdc++.h>
using namespace std;
#define Fr(i,a,b) for(int i=a;i<=b;i++)
#define For(i,a,b) for(int i=a;i<b;i++)
#define Frd(i,a,b) for(int i=a;i>=b;i--)
#define Ford(i,a,b) for(int i=a;i>b;i--)
#define dembit1(x) __builtin_popcountll(x)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
const int mod=1e9+7;
const int oo=INT_MAX-1;
const int N=1e6+2;
int n,a[N],fl[N],fr[N],gl[N],gr[N];
ii ans;

int main()
{
    scanf("%d",&n);
    Fr(i,1,n) scanf("%d",&a[i]);
    fl[1]=gl[1]=1;
    Fr(i,2,n)
    {
        if(a[i]>a[i-1]) fl[i]=fl[i-1]+1;
        else fl[i]=1;
        if(a[i]<a[i-1]) gl[i]=gl[i-1]+1;
        else gl[i]=1;
    }
    fr[n]=gr[n]=1;
    Frd(i,n-1,1)
    {
        if(a[i]>a[i+1]) fr[i]=fr[i+1]+1;
        else fr[i]=1;
        if(a[i]<a[i+1]) gr[i]=gr[i+1]+1;
        else gr[i]=1;
    }
    ans=ii(0,0);
    Fr(i,1,n)
    {
        ans.fi=max(ans.fi,min(fl[i]-1,fr[i]-1));
        ans.se=max(ans.se,min(gl[i]-1,gr[i]-1));
    }
    printf("%d %d",ans.fi,ans.se);
    return 0;
}
