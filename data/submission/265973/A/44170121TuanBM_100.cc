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
const int oo=INT_MAX;
const int N = 10003;
<<<<<<< Updated upstream
int n,k,a[N],b[N],ans;

int main()
{
    scanf("%d %d",&n,&k);
    Fr(i,1,n) scanf("%d",&a[i]);
    b[0]=0,ans=0;
    Fr(i,1,n) b[i]=b[i-1]+a[i];
    Fr(i,1,n)
    {
        Fr(j,i,n)
        {
            if((b[j]-b[i-1])%k==0) ans++;
        }
    }
    printf("%d",ans);
	return 0;
}
=======
int n,k,a[N],b[N],ans;

int main()
{
    scanf("%d %d",&n,&k);
    Fr(i,1,n) scanf("%d",&a[i]);
    b[0]=0,ans=0;
    Fr(i,1,n) b[i]=b[i-1]+a[i];
    Fr(i,1,n)
    {
        Fr(j,i,n)
        {
            if((b[j]-b[i-1])%k==0) ans++;
        }
    }
    printf("%d",ans);
	return 0;
}
>>>>>>> Stashed changes
