<<<<<<< Updated upstream
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int N, K;

ll *S;

void input(){
    cin >> N >> K;
    S = new ll[N];

    ll s = 0;
    int e;

    for(int i = 0 ; i < N ; i ++){
        cin >> e;
        s += e;
        S[i] = s;
    }
}

void go(){
    int cnt = 0;
    for(int i = 0 ; i < N - 1 ; i ++){
        if(S[i] % K == 0) cnt ++;
        for(int j = i + 1 ; j < N ; j ++){
            if((S[j] - S[i]) % K == 0) cnt++;
        }
    }

    cout << cnt;
}

int main(){
    input();
    go();
    return 0;
=======
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int N, K;

ll *S;

void input(){
    cin >> N >> K;
    S = new ll[N];

    ll s = 0;
    int e;

    for(int i = 0 ; i < N ; i ++){
        cin >> e;
        s += e;
        S[i] = s;
    }
}

void go(){
    int cnt = 0;
    for(int i = 0 ; i < N - 1 ; i ++){
        if(S[i] % K == 0) cnt ++;
        for(int j = i + 1 ; j < N ; j ++){
            if((S[j] - S[i]) % K == 0) cnt++;
        }
    }

    cout << cnt;
}

int main(){
    input();
    go();
    return 0;
>>>>>>> Stashed changes
}