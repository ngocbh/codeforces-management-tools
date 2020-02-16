#include<stdio.h>
#include<string.h>
char a[150000],b[150000];
int main()
{
	fflush(stdin);
	gets(a);
	int i,j=0;
	for(i=0;i<strlen(a);i++)
	{
		char last;
	    last=a[i];
		while(a[i+1]==last)
		{
			i++;
			}
			b[j]=last;
			j++;
	}
	b[j]='\0';
	puts(b);
}