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
const ll mod=1e9+7;
<<<<<<< Updated upstream
const int oo=INT_MAX;
const int N=100011;
int n;
ll f[N];

int main()
{
    scanf("%d",&n);
    f[0]=f[1]=1ll;
    f[2]=4;
    Fr(i,3,n)
    {
        f[i]=(((f[i-1]*3ll)%mod+(f[i-1]-f[i-2])%mod)%mod)%mod;
    }
    printf("%lld",f[n]);
	return 0;
}
=======
const int oo=INT_MAX;
const int N=100011;
int n;
ll f[N];

int main()
{
    scanf("%d",&n);
    f[0]=f[1]=1ll;
    f[2]=4;
    Fr(i,3,n)
    {
        f[i]=(((f[i-1]*3ll)%mod+(f[i-1]-f[i-2])%mod)%mod)%mod;
    }
    printf("%lld",f[n]);
	return 0;
}
>>>>>>> Stashed changes
