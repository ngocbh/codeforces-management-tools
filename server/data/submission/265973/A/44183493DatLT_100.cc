#include<iostream>
using namespace std;

int main()
{
    int n, k;
    int a[10000];
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum;
    int counter = 0;
    for(int i = 0; i < n - 1; i++){
        sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum % k == 0) counter ++;
        }
    }
    cout << counter;
    return 0;
}