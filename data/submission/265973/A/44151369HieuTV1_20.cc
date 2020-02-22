# include <iostream>
# include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n, k, i, count = 0;
    int *arr;
    cin >> n;
    cin >> k;
    arr = (int *) malloc(n * sizeof(int));
    for ( i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }
    
    for ( i = 1; i <= n; i++) // so phan tu cua sub arr
    {
        for (int j = i; j < n; j++) // start index -> end index
        {
            int tmp = 0;
            for (int z = j; z < i+j && i+j < n; z++)
            {
                tmp += arr[z];                
            }
            if (tmp % k == 0)
            {
                count++;
            }
        }
    }
    
    cout << count;
    return 0;
}
