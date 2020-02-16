#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define size 30000

int cmin;
int fopt;
int f;
int n;

int wAdd[size];
int cAdd[size];
bool flag[size];
int woking[size];

bool UCV(int k, int i)
{
    return !flag[i];
}

int cost(int p, int q)
{
    return pow(wAdd[p] - cAdd[q], 2);
}

void solve(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (UCV(k, i))
        {
            flag[i] = true;
            int temp = cost(k, i);
            f += temp;
            if (k == n - 1)
            {
                fopt = min(f, fopt);
            }
            else if (f + (n - k - 1) * cmin < fopt)
                solve(k + 1);

            f -= temp;
            flag[i] = false;
        }
    }
}

void Input()
{
    cmin = 60000;
    fopt = 2000000000;
    f = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> wAdd[i];
        flag[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cAdd[i];
        for (int j = 0; j < n; j++)
        {
            cmin = min(cmin, cost(j, i));
        }
    }
    solve(0);
    cout << fopt;
}

int main()
{
    Input();
    return 0;
}