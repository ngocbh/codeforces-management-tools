
#include <stdio.h>
#include <string.h>
int main()
{
char a[150000];
gets(a);

int i=0;
while(i<strlen(a)-1)
{
if(a[i]==a[i+1])
{
strcpy(&a[i],&a[i+1]);
}
else
i++;
}

printf("%s",a);
}