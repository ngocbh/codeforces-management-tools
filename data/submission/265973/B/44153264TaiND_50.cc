<<<<<<< Updated upstream
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 101;

int d, n;
int c[MAX][MAX];
int xL, yL;

int sum(int x, int y)
{
    int s = 0;
    int maxX = min(x + d, MAX);
    int maxY = min(y + d, MAX);
    int minX = max(x - d, 0);
    int minY = max(y - d, 0);
    for (int x0 = minX; x0 <= maxX; x0++)
    {
        for (int y0 = minY; y0 <= maxY; y0++)
        {
            s += c[x0][y0];
        }
    }
    return s;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int x, y, z;
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        c[x][y] = z;
    }

    int cmax = 0;
    int l = 0;
    for (x = 0; x <= MAX; x++)
    {
        for (y = 0; y <= MAX; y++)
        {
            int t = sum(x, y);
            if (t > cmax)
            {
                cmax = t;
                l = 0;
                xL = x;
                yL = y;
                l++;
            }
        }
    }
    cout << xL << " " << yL << " " << cmax;
    return 0;
=======
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 101;

int d, n;
int c[MAX][MAX];
int xL, yL;

int sum(int x, int y)
{
    int s = 0;
    int maxX = min(x + d, MAX);
    int maxY = min(y + d, MAX);
    int minX = max(x - d, 0);
    int minY = max(y - d, 0);
    for (int x0 = minX; x0 <= maxX; x0++)
    {
        for (int y0 = minY; y0 <= maxY; y0++)
        {
            s += c[x0][y0];
        }
    }
    return s;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int x, y, z;
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        c[x][y] = z;
    }

    int cmax = 0;
    int l = 0;
    for (x = 0; x <= MAX; x++)
    {
        for (y = 0; y <= MAX; y++)
        {
            int t = sum(x, y);
            if (t > cmax)
            {
                cmax = t;
                l = 0;
                xL = x;
                yL = y;
                l++;
            }
        }
    }
    cout << xL << " " << yL << " " << cmax;
    return 0;
>>>>>>> Stashed changes
}