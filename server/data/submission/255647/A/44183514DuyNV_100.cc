#include <iostream>
#include <cstdio>
#include<cstring>
#include <string>
using namespace std;
char s[150000],s1[150000];
int k=0;
void xaulap()
{
    s1[k]=s[0];
    for (int i=0;i<strlen(s)-1;i++)
    if (s[i]!=s[i+1])
    {
        k=k+1;
        s1[k]=s[i+1];
    }
    cout << s1;
}
int main()
{
    fflush(stdin);
    gets(s);
    xaulap();
}
