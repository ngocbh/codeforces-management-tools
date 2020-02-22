#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char a[150000];
char s[150000];
int i,j,k=0;
fflush(stdin);
gets(a);
int n = strlen(a);
for(i=0;i<n;i++){
if(a[i]!=a[i+1]){s[k]=a[i];k++;}
}
puts(s);
}