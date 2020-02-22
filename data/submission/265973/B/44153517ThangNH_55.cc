#include <bits/stdc++.h>
using namespace std;
const int SIZE = 101;

int main()
{
    //freopen("test.txt", "r", stdin);

    int d, n;
    cin >> d >> n;

    int s[200][200];

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        s[x][y] = z;
    }

    long long a = 0, b = 0, c = 0;

    for (int i = d; i <= 100 - d; i++)
    {
        for (int j = d; j <= 100 - d; j++)
        {
            long long temp = 0;
            for (int x0 = i - d; x0 <= i + d; x0++)
            {
                for (int y0 = j - d; y0 <= j + d; y0++)
                {
                    temp += s[x0][y0];
                }
                if (temp > c)
                {
                    c = temp;
                    a = i;
                    b = j;
                }
            }
        }
    }

    cout << a << " " << b << " " << c;
}