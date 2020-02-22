#include <bits/stdc++.h>

using namespace std;

long n, k;
int a[11000];


void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
}

long solve() {
    long result = 0;
    for (int i = 1; i <= n; i++)
    {
        long sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum += a[j];
            if (sum % k == 0)
            {
                result += 1;
            }
            
        }
        
    }
    return result;
}

int main() {
    input();
    long result = solve();
    cout << result;
    return 0;
}