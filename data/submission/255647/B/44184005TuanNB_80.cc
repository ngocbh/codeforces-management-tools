#include <iostream>
using namespace std;
long long int min(long long int x,long long int y)
{
    if (x<y) return(x);
    else return(y);
}
int main()
{
    long long int a[1000000],phankhuc[1000000],trangthai[1000000];
    long long int  n,i,d,num,maxloi,maxlom,k;
    cin>>n;
    for (i=0;i<=n-1;i++) cin>>a[i];
    d=2;num=0;
    for (i=1;i<=n-1;i++)
    {
        if (a[i]>a[i-1])
        {
            if (d!=1)
            {
                num++;
                trangthai[num]=1;
                phankhuc[num]=1;
                d=1;
            }
            else
            {
                phankhuc[num]++;
            }
        }
        else 
        {
            if (a[i]<a[i-1])
            {
                if (d!=-1)
                {
                    num++;
                    phankhuc[num]=1;
                    trangthai[num]=-1;
                    d=-1;
                }
                else phankhuc[num]++;
            }
            else
            {
                if (d!=0)
                {
                    num++;
                    phankhuc[num]=1;
                    trangthai[num]=0;
                    d=0;
                }
                else phankhuc[num]++;
            }
        }
    }
    maxloi=0;
    maxlom=0;
    for (i=1;i<=num-1;i++) 
    {
        if ((trangthai[i]==1)&&(trangthai[i+1]==-1))
        {
            k=min(phankhuc[i],phankhuc[i+1]);
            if (k>maxloi) maxloi=k;
        }
        if ((trangthai[i]==-1)&&(trangthai[i+1]==1))
        {
            k=min(phankhuc[i],phankhuc[i+1]);
            if (k>maxlom) maxlom=k;
        }
    }
    cout<<maxloi<<" "<<maxlom;
}