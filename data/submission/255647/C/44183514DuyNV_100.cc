#include <iostream>
#include <cstdio>
#include <cmath>
int a[30000],b[30000],n;
using namespace std;
void swap (int* x, int* y)
{
    int tg= *x;
    *x= *y;
    *y= tg;
}
int partition (int *a,int l, int r, int indexpivot)
{
    int i;
    int pivot = a[indexpivot];
    swap(&a[indexpivot],&a[r]);
    int storeindex=l;
    for (i=l;i<r;i++)
    {
        if (a[i]<pivot)
        {
            swap (&a[i],&a[storeindex]);
            storeindex ++;
        }
    }
    swap (&a[storeindex],&a[r]);
    return storeindex;
}
void qs(int *a, int l, int r)
{
    if (l<r)
    {
        int m=(l+r)/2;
        m=partition(a,l,r,m);
        if (l<m) qs(a,l,m-1);
        if (m<r) qs(a,m+1,r);
    }
}
int main()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    qs(a,0,n-1);
    qs(b,0,n-1);
    long long sum=0;
    for (int i=0;i<n;i++) sum = sum+pow(b[i]-a[i],2);
    cout << sum;
}
