#include <iostream>
#include <math.h>
#include <stack>
#include <iterator>
#include <algorithm>

using namespace std;

int chiphimin(pair<int,bool> ptho[], pair<int,bool> pkhach[], int n)
{
    int res = 0;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        int min = 999999999;
        for (int j = 0; j < n; j++)
        {
            if(pkhach[j].second) continue;
            tmp = pow(abs(ptho[i].first - pkhach[j].first), 2);
            if (tmp < min)
            {   
                min = tmp;
                if (j > 0) {
                    pkhach[j].second = true;
                    pkhach[j-1].second = false;
                }
            }
        }
        res += min;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int tho[n], khach[n];
    pair<int, bool> ptho[n];
    pair<int, bool> pkhach[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> tho[i];
        ptho[i] = {tho[i], false};
    }
    for (int i = 0; i < n; i++)
    {
        cin >> khach[i];
        pkhach[i] = {khach[i], false};
    }
    cout << chiphimin(ptho, pkhach, n);
    return 0;
}
