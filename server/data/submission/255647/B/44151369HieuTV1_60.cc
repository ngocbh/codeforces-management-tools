#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

// Global var
int n, hill, valley;
int a[MAX];
bool up;


void inputData()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}


int Hill(int t)
{
    if (t == n)
        return n;

    int i = t;
    int j = -1;
    int k = -1;
    for (int temp = t; temp < n; temp++)
    {
        if (a[temp] == a[temp + 1] && j == -1)
            return temp + 1;
        if (a[temp] > a[temp + 1])
        {
            if (j == -1)
            {
                j = temp;
                k = temp + 1;
            }
        }
        if (a[temp] <= a[temp + 1])
        {
            if (j != -1)
            {
                k = temp;
                break;
            }
        }
    }
    if (k >= n)
        return n;
    int depth = min(j - i, k - j);
    hill = max(hill, depth);
    if (k == -1)
        return n;
    else
        return j;
}

int Valley(int t)
{
    // end
    if (t == n)
        return n;

    int i = t, j = -1, k = -1;
    for (int tmp = t; tmp < n; tmp++) {
        // Base case
        if (a[tmp] == a[tmp + 1] && j == -1)
            return tmp + 1;

        if (a[tmp] < a[tmp + 1])
            if (j == -1)
            {
                j = tmp;
                k = tmp + 1;
            }

        if (a[tmp] >= a[tmp + 1])
            if (j != -1)
            {
                k = tmp;
                break;
            }
    }
    if (k >= n)
        return n;
    int depth = min(j - i, k - j);
    valley = max(valley, depth);
    if (k == -1) return n;
    else return j;
}

void doProcess()
{
    hill = 0;
    valley = 0;

    for (int i = 0; i < n - 1;)
    {
        if (a[i] == a[i + 1])
            i++;

        if (a[i] < a[i + 1])
        {
            i = Hill(i);
        }
        if (a[i] >= a[i + 1])
        {
            i = Valley(i);
        }
    }
    cout << hill << " " << valley;
}

int main()
{
    inputData();
    doProcess();
    return 0;
}