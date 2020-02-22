#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	char s[150000],kq[150000];
int main()
{
	int i,j,k,n;
	fflush(stdin);gets(s);
	n=strlen(s);
	k=0;
	for (i=0;i<n;i++)
	{
		if (s[i]!=s[i+1] ) {	kq[k]=s[i];k++;}
	}
	puts(kq);
}