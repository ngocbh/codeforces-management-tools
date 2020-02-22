#include <iostream>

using namespace std;

const int MAX = 1000 + 10;
int a[MAX];

int main()
{
    int n;
    // freopen("in.txt", "r", stdin);
    cin >> n;
    a[1] = 1;
    a[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] * 3 + 2 * a[i - 2] + 1;
    }
    cout << a[n];
    return 0;
}