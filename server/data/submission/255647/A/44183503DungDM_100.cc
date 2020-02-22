#include <bits/stdc++.h>

#define MAX_INT 2000000000
#define ff(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

typedef long long ll;


int main() {
    string s; getline(cin, s);
    char c = s[0]; cout << s[0];
    ff(i, 1, s.length() - 1) {
        if (s[i] != c) {
            cout << s[i];
            c = s[i];
        }
    }
    return 0;
}