<<<<<<< Updated upstream
#include <iostream>

using namespace std;

int N, K;
int a[10001];
int b;

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j++)
        {
            b = b + a[j];
            if((b % K) == 0) cnt++;
        }
        b = 0;
    }
    cout << cnt;
}
=======
#include <iostream>

using namespace std;

int N, K;
int a[10001];
int b;

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j++)
        {
            b = b + a[j];
            if((b % K) == 0) cnt++;
        }
        b = 0;
    }
    cout << cnt;
}
>>>>>>> Stashed changes
