#include <iostream>
#include <string>

using namespace std;

int n;
bool check[150001];

int main()
{
    //in: solution
    //for (int i = 0; i <= n - 1; i++) check[i] = true;
    string s;
    getline(cin, s);
    n = s.length();
    for (int i = 0; i <= n - 1; i++) check[i] = true;
    for (int i = 1; i <= n - 1; i++) {
        if (s[i] == s[i-1]) check[i] = false;
    }
    for (int i = 0; i <= n - 1; i++) {
        if (check[i]) cout << s[i];
    }

    return 0;
}
