<<<<<<< Updated upstream
#include <iostream>
using namespace std;

int N, K;
int a[10001];
int sum;

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
            sum = sum + a[j];
            if((sum % K) == 0) cnt++;
        }
        sum = 0;
    }
    cout << cnt;
}
=======
#include <iostream>
using namespace std;

int N, K;
int a[10001];
int sum;

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
            sum = sum + a[j];
            if((sum % K) == 0) cnt++;
        }
        sum = 0;
    }
    cout << cnt;
}
>>>>>>> Stashed changes
