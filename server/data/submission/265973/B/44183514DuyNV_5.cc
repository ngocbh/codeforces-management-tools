#include <iostream>
#include <cstdio>
using namespace std;
int d,n,x[20001],y[20001],c[100][100]={0},f[100][100]={0},g[100][100]={0},maxx,a,b;
int main()
{
    cin >> d >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> x[i] >> y[i];
        cin >> c[x[i]][y[i]];
    }
    for (int i=1;i<=100;i++)
        for (int j=1;j<=100;j++)
            for (int k=1;k<=n;k++)
                if (x[k]<=i && y[k] <=j) f[i][j]=f[i][j]+c[x[k]][y[k]];
    maxx=0;
    for (int i=1+d;i<=100-d;i++)
        for (int j=1+d;j<=i;j++)
        {
            /*if (i-d<1 && j-d <1) g[i][j]=f[i+d][j+d] +f[1][1]-f[i+d][1]-f[1][j+d];
            else if (i-d<1) g[i][j]=f[i+d][j+d] +f[1][j-d]-f[i+d][j-d]-f[1][j+d];
            else if (j-d<1) g[i][j]=f[i+d][j+d] +f[i-d][1]-f[i+d][1]-f[i-d][j+d];
            else if (i+d>100 && j+d >100) g[i][j]=f[100][100]+f[i-d][j-d]-f[100][j-d]-f[i-d][100];
            else if (i+d>100) g[i][j]=f[100][j+d]+f[i-d][j-d]-f[100][j-d]+f[i-d][j+d];
            else if (j+d>100) g[i][j]=f[100][j+d]+f[i-d][j-d]-f[i+d][j-d]+f[i-d][100];
            else */g[i][j]=f[i+d][j+d]+f[i-d][j-d]-f[i+d][j-d]-f[i-d][j+d]+c[i-d][j-d];
            if (g[i][j]>maxx)
            {
                maxx=g[i][j];
                a=i;
                b=j;
            }
        }
    cout << a << " " <<  b << " " <<  maxx;
    return 0;
}
