<<<<<<< Updated upstream
#include <iostream>
#include <math.h>
using namespace std;

long sub[10000][10000];
long n, k;
long kq = 0;

void capnhap(long vi,long i)
{
    sub[i][i] = vi; 
    if( vi % k == 0)
        kq++;
    for(long j = 0; j < i; j++)
    {
        sub[j][i] = sub[j][i-1] + vi;
        if ( sub[j][i] % k == 0)
            kq++;
    }
}


int main()
{
    long ni;
    cin >> n >> k;

    for(long i = 0; i < n; i++)
    {
        cin >> ni;
        capnhap(ni, i);
    }
    cout << kq;
    return 0;
=======
#include <iostream>
#include <math.h>
using namespace std;

long sub[10000][10000];
long n, k;
long kq = 0;

void capnhap(long vi,long i)
{
    sub[i][i] = vi; 
    if( vi % k == 0)
        kq++;
    for(long j = 0; j < i; j++)
    {
        sub[j][i] = sub[j][i-1] + vi;
        if ( sub[j][i] % k == 0)
            kq++;
    }
}


int main()
{
    long ni;
    cin >> n >> k;

    for(long i = 0; i < n; i++)
    {
        cin >> ni;
        capnhap(ni, i);
    }
    cout << kq;
    return 0;
>>>>>>> Stashed changes
}