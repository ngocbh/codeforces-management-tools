#include<bits/stdc++.h>
using namespace std;

int n, k, a[10001] = {};
long long s[10001] = {};
int q = 0;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1]+a[i];
        for(int j = 0; j < i; j++){
            if((s[i] - s[j]) % k == 0) q++;
        }
    }
    cout << q << endl;
}
