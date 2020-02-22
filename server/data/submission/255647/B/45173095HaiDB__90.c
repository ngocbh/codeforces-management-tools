#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n;
    scanf("%d", &n);
    long *day = (long*)malloc(n*sizeof(long));

    for(int i=0; i<n; i++)
        scanf("%d", &day[i]);
    int kq_doi = 0, kq_tl = 0;

    int i2 = 0;
    for(int i=0; i<n-1; i++){
        if(day[i] > day[i+1]){
            int j = i, k=0;
            for(k=i; k<n; k++)
                if(day[k] < day[k+1])
                    break;

            int kq2 = j-i2;
            if(kq2 > k-j)
                kq2 = k-j;
            if(kq2 > kq_doi )
                kq_doi = kq2;
            i = k;
            i2 = k;
        }
    }

    i2 = 0;
    for(int i=0; i<n-1; i++){
        if(day[i] < day[i+1]){
            int j = i, k=0;
            for(k=i; k<n; k++)
                if(day[k] > day[k+1])
                    break;

            int kq2 = j-i2;
            if(kq2 > k-j)
                kq2 = k-j;
            if(kq2 > kq_tl )
                kq_tl = kq2;
            i = k;
            i2 = k;
        }
    }

    printf("%d %d", kq_doi, kq_tl);
    return 0;
}
