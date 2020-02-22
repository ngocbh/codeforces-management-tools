#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,i1,j1,k1,i2,j2,k2,min1=1000000,min2=1000000;
int a[1000000];
int doi()
{
    int demo;
    int h=0;
    while (h<n)
    {
        if (a[h+1]>a[h])
        {
            i1=h;
            h++;
            while (a[h+1]>a[h] && h<n-1) h++;
            j1=h;
            while (a[h+1]<a[h] && h<n-1) h++;
            k1=h;
        }
        else h++;
        if (i1!=j1 && j1!=k1)
        {
            demo=j1-i1;
            if (j1-i1>k1-j1) demo=k1-j1;
        }
    }
    if (demo<min1) min1=demo;
    if (min1==1000000) return 0;
    return min1;
}
int thunglung()
{
    int demo;
    int h=0;
    while (h<n)
    {
        if (a[h+1]<a[h])
        {
            i2=h;
            h++;
            while (a[h+1]<a[h] && h<n-1) h++;
            j2=h;
            while (a[h+1]>a[h] && h<n-1) h++;
            k2=h;
        }
        else h++;
        if (i2!=j2 && j2!=k2)
        {
            cout <<endl;
            demo=j2-i2;
            if (j2-i2>k2-j2) demo=k2-j2;
        }
    }
    if (demo<min2) min2=demo;
    if (min2==1000000) return 0;
    return min2;
}
int main()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << doi() << " " << thunglung();
}
