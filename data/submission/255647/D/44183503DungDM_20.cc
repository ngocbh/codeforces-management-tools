#include <bits/stdc++.h>

#define MAX_ll 2000000000
#define ff(i, a, b) for (ll i = a; i <= b; i++)
using namespace std;

typedef long long ll;

ll l[10000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);        
    ll n; cin >> n;
    string s = "";
    ff(i, 1, n) {
        stringstream ss; ss << i;
        string temp1 = ss.str(), temp2 = temp1; ll count = 1;
        // temp2[0] = temp1[0];
        ff(j, 1, temp1.length()-1) {
            if (temp1[j] != temp1[j-1]) {
                temp2[count] = temp1[j]; count++;
            }
        }
        ll first = 0; while (s[s.length()-1] == temp2[first]) first++;
        temp2 = temp2.substr(first, count);
        s = s + temp2;
        l[i] = s.length();
    }

    // cout << s << endl;
    // ff(i, 1, 20) cout << l[i] << " ";
    ff(i, 1, n) { if (l[i] == n) {cout << i; return 0;}}
    return 0;
}