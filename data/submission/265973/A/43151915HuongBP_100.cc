#include <iostream>

using namespace std;

#define MAX 10000

int n, k;
int a[MAX];
unsigned long long sum;
int count;

void Input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Solve()
{
    count = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum % k == 0)
                count++;
        }
    }
    cout << count;
}

int main(int argc, char const *argv[])
{
    Input();
    Solve();
    return 0;
}
