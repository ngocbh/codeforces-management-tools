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
int m,n,b[N],vt[N],f[M],luu[N],ans,res;
ii a[M];

void dfs(int k)
{
    if(k>n)
    {
        if(res<ans)
        {
            ans=res;
            Fr(i,1,n) luu[i]=vt[i];
        }
        return;
    }
    Fr(i,1,m) if(f[i]+b[k]<=a[i].fi && (res+b[k]*a[i].se)<ans)
    {
        f[i]=f[i]+b[k];
        res=res+b[k]*a[i].se;
        vt[k]=i;
        dfs(k+1);
        f[i]=f[i]-b[k];
        res=res-b[k]*a[i].se;
    }
    vt[k]=0;
    return;
}

int main()
{
    scanf("%d",&m);
    Fr(i,1,m) scanf("%d",&a[i].fi);
    Fr(i,1,m) scanf("%d",&a[i].se);
    scanf("%d",&n);
    Fr(i,1,n) scanf("%d",&b[i]);
    ans=oo,res=0;
    dfs(1);
    if(ans!=oo)
    {
        printf("%d\n",ans);
        vector<int> ve[M];
        Fr(i,1,n) ve[luu[i]].push_back(i);
        Fr(i,1,m)
        {
            printf("%d ",ve[i].size());
            For(j,0,ve[i].size()) printf("%d ",ve[i][j]);
            printf("\n");
        }
    }
    else printf("-1");
    return 0;
}
/*
5
18 24 20 5 100 10 15 14 8 30
14
5 8 7 1 2 6 10 15 9 13 17 3 4 5
*/
