#include <iostream>
 
using namespace std;
typedef unsigned long long ull;
 
int main() {
    int n;
    cin >> n;
    ull q[2*n + 1], K = 1e9 + 7;
    q[1] = q[2] = q[3] = 1;
    q[0] = 0;
    for(int i = 4; i <= 2*n; i++) {
        if(i % 2 == 0) {
            q[i] = 2*((q[i - 1] + q[i - 2]) % K);
        } else {
            q[i] = q[i - 1];
        }
    }
    cout << q[2*n];
    return 0; 
}