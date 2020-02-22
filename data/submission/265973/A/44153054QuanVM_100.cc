<<<<<<< Updated upstream
#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int a[N + 1];
    ll s[N + 1];
    s[0] = 0;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    ll Q = 0;
    for(int i = 1; i < N; i++) {
        for(int j = i; j <= N; j++) {
            if((s[j] - s[i] + a[i]) % K == 0) {
                Q++;
            }
        }
    }
    printf("%lld", Q);
    return 0;
=======
#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int a[N + 1];
    ll s[N + 1];
    s[0] = 0;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    ll Q = 0;
    for(int i = 1; i < N; i++) {
        for(int j = i; j <= N; j++) {
            if((s[j] - s[i] + a[i]) % K == 0) {
                Q++;
            }
        }
    }
    printf("%lld", Q);
    return 0;
>>>>>>> Stashed changes
}