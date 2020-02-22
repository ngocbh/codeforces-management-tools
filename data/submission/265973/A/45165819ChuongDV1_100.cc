#include <bits/stdc++.h>

using namespace std;

int a[10004];
int n, k;
long counter = 0;


int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin>> a[i];
    long long sum;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += a[j];
            if(sum % k == 0)
                counter++;
        }
    }
    cout << counter;
}
