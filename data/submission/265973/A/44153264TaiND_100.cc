#include <iostream>

using namespace std;

const int MAX = 10000 + 5;

int n, k;
int a[MAX];
int c;

int main()
{
    // freopen("in.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    c = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % k == 0)
            c++;
        sum = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            sum += a[j];
            if (sum % k == 0)
                c++;
        }
        sum = 0;
    }
    cout << c;
    return 0;
}