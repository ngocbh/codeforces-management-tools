#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int sum, i, j, n, k, cnt = 0;

    scanf("%d %d", &n, &k);
    arr = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", arr + i);

    for(i = 0; i < n; i++)
    {
        sum = 0;
        for(j = i; j < n; j++)
        {
            sum += arr[j];
            if(0 == (sum % k))
                cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}
