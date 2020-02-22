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
const int N = 111;
int d,n,b[N][N];

struct Rat
{
    int fi,se;
    int val;
} a[N*N],ans;

int calc(int x,int y)
{
    int f=max(x-d,1), ff=max(y-d,1);
    int g=min(x+d,102), gg=min(y+d,102);
    return b[g][gg]+b[f-1][ff-1]-b[g][ff-1]-b[f-1][gg];
}

int main()
{
    scanf("%d",&d);
    scanf("%d",&n);
    Fr(i,1,n)
    {
        scanf("%d %d %d",&a[i].fi,&a[i].se,&a[i].val);
        b[a[i].fi+1][a[i].se+1]=a[i].val;
    }
    Fr(i,1,102)
    {
        Fr(j,1,102)
        {
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    }
    ans.fi=ans.se=101,ans.val=0;
    Fr(i,1,102)
    {
        Fr(j,1,102)
        {
            int temp = calc(i,j);
            if(temp>ans.val)
            {
                ans.fi=i,ans.se=j,ans.val=temp;
            }
            else if(temp==ans.val)
            {
                if(ans.fi>i || (ans.fi==i && ans.se>j))
                {
                    ans.fi=i,ans.se=j;
                }
            }
        }
    }
    printf("%d %d %d",ans.fi-1,ans.se-1,ans.val);
    return 0;
}
/*
3
4
4 4 10
6 6 20
10 10 50
14 14 100
*/
