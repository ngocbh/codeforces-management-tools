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
const int N=30003;
int n,a[N],b[N];
ll ans;

int main()
{
    scanf("%d",&n);
    Fr(i,1,n) scanf("%d",&a[i]);
    Fr(i,1,n) scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    Fr(i,1,n) ans+=1ll*(b[i]-a[i])*(b[i]-a[i]);
    printf("%lld",ans);
    return 0;
}
