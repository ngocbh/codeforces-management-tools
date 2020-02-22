<<<<<<< Updated upstream
#include <bits/stdc++.h>

using namespace std;

struct rat
{
    /* data */
    int x;
    int y;
    int c;
};

int arr[100][100];
rat rats[20000];
int n, d;
int maxX = 0, maxY = 0, minX = 100, minY = 100;

void solve()
{
    int result = 0;
    int xResult = -1, yResult = -1;

    for (int i = minX; i < maxX; ++i)
    {
        for (int j = minY; j < maxY; ++j)
        {
            int sum = 0;
            for (int k = 0; k < n; ++k)
            {
                rat r = rats[k];
                if (max(abs(r.x - i), abs(r.y - j)) <= d)
                {
                    sum += r.c;
                }
            }
            if(sum > result){
                result = sum;
                xResult = i;
                yResult = j;
            }
        }
    }
    cout << xResult << endl;
    cout << yResult << endl;
    cout << result << endl;

}

int main()
{
    cin >> d >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        rat r = {x, y, c};
        rats[i] = r;
        if (x > maxX)
        {
            maxX = x;
        }
        if (y > maxY)
        {
            maxY = y;
        }
        if (x < minX)
        {
            minX = x;
        }
        if (y < minY)
        {
            minY = y;
        }
    }
    solve();
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

struct rat
{
    /* data */
    int x;
    int y;
    int c;
};

int arr[100][100];
rat rats[20000];
int n, d;
int maxX = 0, maxY = 0, minX = 100, minY = 100;

void solve()
{
    int result = 0;
    int xResult = -1, yResult = -1;

    for (int i = minX; i < maxX; ++i)
    {
        for (int j = minY; j < maxY; ++j)
        {
            int sum = 0;
            for (int k = 0; k < n; ++k)
            {
                rat r = rats[k];
                if (max(abs(r.x - i), abs(r.y - j)) <= d)
                {
                    sum += r.c;
                }
            }
            if(sum > result){
                result = sum;
                xResult = i;
                yResult = j;
            }
        }
    }
    cout << xResult << endl;
    cout << yResult << endl;
    cout << result << endl;

}

int main()
{
    cin >> d >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        rat r = {x, y, c};
        rats[i] = r;
        if (x > maxX)
        {
            maxX = x;
        }
        if (y > maxY)
        {
            maxY = y;
        }
        if (x < minX)
        {
            minX = x;
        }
        if (y < minY)
        {
            minY = y;
        }
    }
    solve();
    return 0;
>>>>>>> Stashed changes
}