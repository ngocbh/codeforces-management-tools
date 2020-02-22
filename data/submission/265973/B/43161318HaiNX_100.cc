#include <bits/stdc++.h>

using namespace std;

int d, n;
struct rat_famyly
{
    int x, y;
    int c;
};
rat_famyly A[20001];

struct boom
{
    int x, y;
    int rat;
};

boom result = {0, 0, 0};

void input() {
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        A[i] = {x , y, c};
    }
    
}

void solve() {
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            int sum_of_defeat = 0;
            for (int k = 1; k <= n; k++)
            {
                if (max(abs(i - A[k].x),abs(j - A[k].y)) <= d)
                {
                    sum_of_defeat += A[k].c;
                }
                
            }
            if (sum_of_defeat > result.rat)
            {
                result = {i, j, sum_of_defeat};
            }
            
        }
        
    }
    
}

int main() {
    input();
    solve();
    cout << result.x << " " << result.y << " " << result.rat;
    return 0;
}