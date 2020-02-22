#include <iostream>
#include <string>
using namespace std;


// const int n = 150000;

int main(int argc, char const *argv[])
{
    string a;
    getline(cin, a); 
    int n = a.length();

    char result[n];
    result[0] = a[0];
    int step = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == result[step])
        {
            continue;
        }else
        {
            result[++step] = a[i];
        } 
    }
    for (int i = 0; i <= step; i++)
    {
        cout << result[i];
    }
    
    return 0;
}
