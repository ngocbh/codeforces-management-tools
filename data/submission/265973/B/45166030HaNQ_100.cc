<<<<<<< Updated upstream
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int arr[100][100] = {0};
    int i, j, p, q, n, d, x, y, num, xmax, ymax;
    long long sum = 0, nmax = 0;

    scanf("%d %d", &d, &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d", &x, &y, &num);
        arr[x - 1][y - 1] = num;
    }

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 100; j++)
        {
            sum = 0;
            for(p = i - d; p <= i + d; p++)
                for(q = j - d; q <= j + d; q++)
                {
                    if(0 <= p && p < 100 && 0 <= q && q < 100)
                    {
                        sum += arr[p][q];
                    }
                }
            if(sum > nmax)
            {
                nmax = sum;
                xmax = i;
                ymax = j;
            }
        }
    }

    printf("%d %d %d", xmax + 1, ymax + 1, nmax);
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int arr[100][100] = {0};
    int i, j, p, q, n, d, x, y, num, xmax, ymax;
    long long sum = 0, nmax = 0;

    scanf("%d %d", &d, &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d", &x, &y, &num);
        arr[x - 1][y - 1] = num;
    }

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 100; j++)
        {
            sum = 0;
            for(p = i - d; p <= i + d; p++)
                for(q = j - d; q <= j + d; q++)
                {
                    if(0 <= p && p < 100 && 0 <= q && q < 100)
                    {
                        sum += arr[p][q];
                    }
                }
            if(sum > nmax)
            {
                nmax = sum;
                xmax = i;
                ymax = j;
            }
        }
    }

    printf("%d %d %d", xmax + 1, ymax + 1, nmax);
    return 0;
}
>>>>>>> Stashed changes
