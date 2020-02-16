#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define size 30000

int cmin;
long long fopt;
int f;
int n;

int wAddress[size];
int cAddress[size];
bool flag[size];

int chiphi(int p, int q)
{
    return pow(wAddress[p] - cAddress[q], 2);
}

void solve(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (flag[i]) return; 
        int gia = chiphi(k, i);
        f += gia;
        flag[i] = true;
        if (k == n - 1)
        {
            if (f < fopt){
                fopt = f;
            }     
        }
        else
        {
            int g = f + (n - k) * cmin;
            if (g < fopt) solve(k + 1);
        }
        f -= gia;
        flag[i] = false;
    
    }
}

void cal()
{
    cmin = 2000000000;
    fopt = 2000000000000000000000;
    f = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> wAddress[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cAddress[i];
        for (int j = 0; j < n; j++)
        {
            int o = chiphi(j, i);
            if (o < cmin)
                cmin = o;
        }
    }
    solve(0);
    cout << fopt;
}

int main()
{
    cal();
    return 0;
}