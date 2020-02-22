#include <iostream>
#include <cstring>

using namespace std;

#define MAX 101

int d, n;
int grid[MAX][MAX];
long long best;
long long sum;
int x, y;

void Input()
{
    memset(grid, 0, sizeof(grid));
    cin >> d >> n;
    int _x, _y, _v;
    for (int i = 0; i < n; i++)
    {
        cin >> _x >> _y >> _v;
        grid[_x][_y] = _v;
    }
}

int calculate(int i, int j)
{
    int startX = (i - d) > 0 ? (i - d) : 0;
    int startY = (j - d) > 0 ? (j - d) : 0;
    int endX = (i + d) < MAX ? (i + d) : (MAX - 1);
    int endY = (j + d) < MAX ? (j + d) : (MAX - 1);
    for (int v = startX; v <= endX; v++)
    {
        for (int k = startY; k <= endY; k++)
        {
            sum += grid[v][k];
        }
    }
    if (best < sum)
    {
        best = sum;
        x = i;
        y = j;
    }
}

void Solve()
{
    best = sum = 0;
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; j < MAX; j++)
        {
            calculate(i, j);
            sum = 0;
        }
    }
    cout << x << " " << y << " " << best;
}

int main(int argc, char const *argv[])
{
    Input();
    Solve();
    return 0;
}
