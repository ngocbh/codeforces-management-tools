<<<<<<< Updated upstream
#include <bits/stdc++.h>

using namespace std;

int arr[1000];
int n, K;

void solve()
{
    int Q = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int sum = 0;
            for (int k = i; k <= j; ++k)
            {
                sum += arr[k];
            }
            if (sum % K == 0)
            {
                Q++;
            }
        }
    }
    cout << Q << endl;
}

int main()
{
    cin >> n >> K;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    solve();
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

int arr[1000];
int n, K;

void solve()
{
    int Q = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int sum = 0;
            for (int k = i; k <= j; ++k)
            {
                sum += arr[k];
            }
            if (sum % K == 0)
            {
                Q++;
            }
        }
    }
    cout << Q << endl;
}

int main()
{
    cin >> n >> K;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    solve();
    return 0;
>>>>>>> Stashed changes
}