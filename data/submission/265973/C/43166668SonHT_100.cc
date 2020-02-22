<<<<<<< Updated upstream
#include <iostream>

using namespace std;
int n;
long long arr[100010];

int main()
{
    cin >> n;
    arr[1] = 1;
    arr[2] = 4;
    for (int i = 3; i <= n; i++) {
        arr[i] = 4 * arr[i - 1] - arr[i - 2];
        while (arr[i] < 0) arr[i] += 1000000007;
        while (arr[i] > 1000000007) arr[i] -= 1000000007;
    }
    arr[n] %= 1000000007;
    cout << arr[n] << endl;
}
=======
#include <iostream>

using namespace std;
int n;
long long arr[100010];

int main()
{
    cin >> n;
    arr[1] = 1;
    arr[2] = 4;
    for (int i = 3; i <= n; i++) {
        arr[i] = 4 * arr[i - 1] - arr[i - 2];
        while (arr[i] < 0) arr[i] += 1000000007;
        while (arr[i] > 1000000007) arr[i] -= 1000000007;
    }
    arr[n] %= 1000000007;
    cout << arr[n] << endl;
}
>>>>>>> Stashed changes
