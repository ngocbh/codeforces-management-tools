<<<<<<< Updated upstream
#include<iostream>

using namespace std;
int n, k;
int arr[1000];

int modsum(int *a, int n, int k){
    if (n ==1)
    {
        return a[0]%k;
    }else
    {
        return ((a[n-1]%k) + modsum(a, n-1, k))%k;
    }
    
    
}

int count(int *a, int n, int k){
    int n_arr = 0;
    for (int  l = 1; l <= n; l++)
    {
        for (int  i = 0; i < n-l+1; i++)
        {
            int sum = 0;
            int tmp[l];
            for (int m = 0; m < l; m++)
            {
                // sum += a[i+m]%k;
                tmp[m] = a[i+m];
            }
            sum = modsum(tmp, l, k);
            if (sum == 0)
            {
                n_arr += 1;
            }
        } 
    }
    // cout << n_arr << endl;
    return n_arr;  
}
int main(int argc, char const *argv[])
{
    // k =3;
    // n = 4;
    // int arr[4] = {3, 2, 4, 5};
    cin >> n;
    cin >> k;
    for (int  i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << count(arr, n, k) << endl;
    return 0;
}

=======
#include<iostream>

using namespace std;
int n, k;
int arr[1000];

int modsum(int *a, int n, int k){
    if (n ==1)
    {
        return a[0]%k;
    }else
    {
        return ((a[n-1]%k) + modsum(a, n-1, k))%k;
    }
    
    
}

int count(int *a, int n, int k){
    int n_arr = 0;
    for (int  l = 1; l <= n; l++)
    {
        for (int  i = 0; i < n-l+1; i++)
        {
            int sum = 0;
            int tmp[l];
            for (int m = 0; m < l; m++)
            {
                // sum += a[i+m]%k;
                tmp[m] = a[i+m];
            }
            sum = modsum(tmp, l, k);
            if (sum == 0)
            {
                n_arr += 1;
            }
        } 
    }
    // cout << n_arr << endl;
    return n_arr;  
}
int main(int argc, char const *argv[])
{
    // k =3;
    // n = 4;
    // int arr[4] = {3, 2, 4, 5};
    cin >> n;
    cin >> k;
    for (int  i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << count(arr, n, k) << endl;
    return 0;
}

>>>>>>> Stashed changes
