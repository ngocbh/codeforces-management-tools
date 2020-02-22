<<<<<<< Updated upstream
#include <iostream>
#include <cstdio>
using namespace std;
long long n,k;
long long a[10000];
int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    long long res=0;
    for (int i=0;i<n;i++)
    {
        long long tong =a[i];
        if (a[i]%k==0) res++;
        for (int j=i+1;j<n;j++)
        {
           tong=tong +a[j];
           if (tong%k==0) res++;
        }
    }
     cout <<  res;
}
=======
#include <iostream>
#include <cstdio>
using namespace std;
long long n,k;
long long a[10000];
int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    long long res=0;
    for (int i=0;i<n;i++)
    {
        long long tong =a[i];
        if (a[i]%k==0) res++;
        for (int j=i+1;j<n;j++)
        {
           tong=tong +a[j];
           if (tong%k==0) res++;
        }
    }
     cout <<  res;
}
>>>>>>> Stashed changes
