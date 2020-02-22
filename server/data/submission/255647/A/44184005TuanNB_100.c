#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char st[300000];
int m,n,i;
int main()
{
    char c;
    fflush(stdin);
    gets(st);
    c=st[0];
    n=strlen(st);
    for (i=0;i<=n-1;i++) if (st[i]!=c)
    {
        printf("%c",c);
        c=st[i];
    }
    printf("%c",c);
}