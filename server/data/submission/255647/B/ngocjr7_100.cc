#include <stdio.h>
#include <algorithm>

using namespace std;

int a[1<<20];
int b[1<<20];
int c[1<<20];

int main()
{
    // FILE *fin = fopen("doi.in", "rt");
    // FILE *fout = fopen("doi.out", "wt");
    // freopen("../in.txt","r",stdin);

    // int t;
    // scanf("%d", &t);

    // for (; t--;)
    // {
    // freopen("../in.txt","r",stdin);
        int n;
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%d", a+i);

        int h, v;

        for (int z=0; z<2; z++)
        {
            h = v;
            v = 0;

            b[0] = 0;
            for (int i=1; i<n; i++)
                b[i] = a[i] > a[i-1] ? b[i-1] : i;

            c[n-1] = n-1;
            for (int i=n-2; i>=0; i--)
                c[i] = a[i] > a[i+1] ? c[i+1] : i;
                
            for (int i=0; i<n; i++)
                v = max(v, min(i-b[i], c[i]-i));

            for (int i=0; i<n; i++)
                a[i] = -a[i];
        }

        printf("%d %d\n", h, v);
    // }

    return 0;
}
