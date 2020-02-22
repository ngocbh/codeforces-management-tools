<<<<<<< Updated upstream
#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1001
#define MOD 1000000007

int n;
unsigned long long x1[MAX];
unsigned long long x2[MAX];

void Input()
{
    cin >> n;
}

unsigned long long AddMod(unsigned long long a, unsigned long long b)
{
    a = a % MOD;
    b = b % MOD;
    unsigned long long tmp = MOD - a;
    if (b < tmp)
        return a + b;
    else
        return b - tmp;
}

void Solve()
{
    x1[1] = 1;
    x2[1] = 0;
    x1[2] = 3;
    x2[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        x1[i] = (x1[i - 1] + x2[i - 1]) * 3;
        unsigned long long tmp = 1;
        for (int j = 0; j < i - 2; j++)
        {
            tmp *= 3;
        }
        x2[i] = tmp;
    }
    cout << AddMod(x1[n], x2[n]);
}

int main(int argc, char const *argv[])
{
    Input();
    Solve();
    return 0;
}
=======
#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1001
#define MOD 1000000007

int n;
unsigned long long x1[MAX];
unsigned long long x2[MAX];

void Input()
{
    cin >> n;
}

unsigned long long AddMod(unsigned long long a, unsigned long long b)
{
    a = a % MOD;
    b = b % MOD;
    unsigned long long tmp = MOD - a;
    if (b < tmp)
        return a + b;
    else
        return b - tmp;
}

void Solve()
{
    x1[1] = 1;
    x2[1] = 0;
    x1[2] = 3;
    x2[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        x1[i] = (x1[i - 1] + x2[i - 1]) * 3;
        unsigned long long tmp = 1;
        for (int j = 0; j < i - 2; j++)
        {
            tmp *= 3;
        }
        x2[i] = tmp;
    }
    cout << AddMod(x1[n], x2[n]);
}

int main(int argc, char const *argv[])
{
    Input();
    Solve();
    return 0;
}
>>>>>>> Stashed changes
