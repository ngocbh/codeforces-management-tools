<<<<<<< Updated upstream
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int main(){

    int n, K, a[MAX];
    cin >> n >> K;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    int s = 0, d = 0;
    for(int i = 1; i<=n; i++){
        s = 0;
        for(int j= i; j<=n; j++){
            s += a[j];

            if (s % K == 0) d++;
        }
    }
    cout << d;
}
=======
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int main(){

    int n, K, a[MAX];
    cin >> n >> K;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    int s = 0, d = 0;
    for(int i = 1; i<=n; i++){
        s = 0;
        for(int j= i; j<=n; j++){
            s += a[j];

            if (s % K == 0) d++;
        }
    }
    cout << d;
}
>>>>>>> Stashed changes
