#include <iostream>
using namespace std;

int n, k, arr[10000];
int sum, res;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    res = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum % k == 0) res++;
        }
    }
    cout << res << endl;
}
