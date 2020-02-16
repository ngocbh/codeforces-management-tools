#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string instring;
    getline(cin, instring);

    // init
    char result[instring.length()];
    result[0] = instring[0];

    int step = 0;
    for (int i = 1; i < instring.length(); i++)
    {
        if (instring[i] == result[step])
            continue;
        else
            result[++step] = instring[i];
    }
    
    // print
    for (int i = 0; i <= step; i++)
    {
        cout << result[i];
    }
    return 0;
}