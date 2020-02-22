#include <iostream>
#include <cstdio>
#define MAXINT 1000000007
using namespace std;
long long n;
long long a=1,b=4,tg;
int main()
{
    cin >> n;
    if (n==1) cout << "1";
    else
    {
    for (int i=3;i<=n;i++)
    {
        tg=b%MAXINT;
        b=(4*b-a)%MAXINT;
        a=tg%MAXINT;
    }
    if (b<0) cout << (b+MAXINT); else cout << b;
    }
}