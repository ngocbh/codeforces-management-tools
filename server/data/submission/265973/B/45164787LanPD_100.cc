#include <iostream>

using namespace std;

int main()
{
    int d,n,x,y,z;
    int arr[105][105] = {{0}};
    long long sum[101][101] = {{0}};
    cin >> d;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x >> y >> z;
        arr[x][y] = z;
    }
    for (int i=1; i<=100; i++)
        for (int j=1; j<=100; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
    int xx,yy;
    long long res = 0;
    for (int i=1; i<=100; i++)
        for (int j=1; j<=100; j++)
        {
            long long tmp = sum[min(i+d,100)][min(j+d,100)]
             - sum[min(i+d,100)][max(j-d-1,0)] - sum[max(i-d-1,0)][min(j+d,100)] + sum[max(i-d-1,0)][max(j-d-1,0)];
            if (tmp > res){
                res = tmp;
                xx = i;
                yy = j;
            }
            else if (tmp == res){
                if (i < xx) {xx=i; yy=j;}
                else if (i==xx && j <yy) {xx=i; yy=j;};
            }
        }
    cout << xx << " " << yy << " " << res;
    return 0;
}
