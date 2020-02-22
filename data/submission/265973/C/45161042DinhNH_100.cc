#include<bits/stdc++.h>
using namespace std;

int n;
long long s[100001] = {}, sum[100001] = {};
int p = 1000000007;
int main(){
    cin >> n;
    s[1] = 1;
    s[2] = 4;
    sum[1] = 1;
    sum[2] = 5;
    for(int i = 3; i <= n; i++){
        s[i] = ((3*s[i - 1]) % p + (2*sum[i-2]) % p + 1) % p;
        sum[i] = (sum[i-1] + s[i]) % p;
    }
    cout << s[n]<< endl;
}
