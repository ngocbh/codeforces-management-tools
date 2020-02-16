#include <iostream>
using namespace std;
#define maxint 1000000000
long limit[100],load[100],thoigian[100],d[100],f[100],num[100],s[100],tt[100],r[100];
long m,n,opt,expense,dmin;
void docdulieu()
{
    int i;
    cin>>m;
    for (i=1;i<=m;i++) cin>>limit[i];
    for (i=1;i<=m;i++) cin>>d[i];
    cin>>n;
    for (i=1;i<=n;i++) cin>>thoigian[i];
    opt=maxint;
    for (i=1;i<=m;i++) load[i]=0;
    expense=0;
    dmin=maxint;
    for (i=1;i<=m;i++) if (d[i]<dmin) dmin=d[i];
    f[n+1]=0;
    for (i=n;i>=1;i--) f[i]=f[i+1]+thoigian[i];
    for (i=1;i<=m;i++) num[i]=0;
}
void search(long x)
{
    long old,i;
    if (x<=n)
    {
        for (i=1;i<=m;i++) if (load[i]+thoigian[x]<=limit[i])
        {
            load[i]=load[i]+thoigian[x];
            tt[x]=i;
            num[i]++;
            old=expense;
            expense=expense+thoigian[x]*d[i];
            if (expense+f[x+1]*dmin<opt) search(x+1);
            load[i]=load[i]-thoigian[x];
            expense=old;
            num[i]--;
        }
    }
    else
    {
        if (expense<opt) 
        {
            opt=expense;
            for (i=1;i<=n;i++) r[i]=tt[i];
            for (i=1;i<=m;i++) s[i]=num[i];
        }
    }
}
int main()
{
    int i,j;
    docdulieu();
    search(1);
    if (opt<maxint) 
    {
        cout<<opt<<endl;
        for (i=1;i<=m;i++)
        {
            cout<<s[i];
            for (j=1;j<=n;j++) if (r[j]==i) cout<<" "<<j;
            cout<<endl;
        }
        {
            
        }
    }
    else cout<<"-1";
}