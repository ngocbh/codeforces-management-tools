<<<<<<< Updated upstream
#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;

int main()
{
 //   freopen("test.txt", "r", stdin);

    int n, k;
    cin >> n >> k;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int answer = 0;
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % k == 0) answer += 1;
        tong = a[i];
        for (int j = i + 1; j < n; j++)
        {
            tong += a[j];
            if (tong % k == 0) answer += 1;
        }
        tong = 0;
    }
    cout << answer;
=======
#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;

int main()
{
 //   freopen("test.txt", "r", stdin);

    int n, k;
    cin >> n >> k;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int answer = 0;
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % k == 0) answer += 1;
        tong = a[i];
        for (int j = i + 1; j < n; j++)
        {
            tong += a[j];
            if (tong % k == 0) answer += 1;
        }
        tong = 0;
    }
    cout << answer;
>>>>>>> Stashed changes
}