#include <iostream>
#include <string>
using namespace std;

string a;
char b[150000];

int main()
{
    getline(cin, a); 
    int n = a.length();
    b[0] = a[0];

    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[k])
        {
            continue;
        }else
        {
            b[++k] = a[i];
        } 
    }

    for (int i = 0; i <= k; i++)
    {
        cout << b[i];
    }
    
    return 0;
}
