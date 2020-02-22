#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char S[150000],kq[150000];int i,j,k=0;
	fflush(stdin);gets(S);int n=strlen(S);
	for (i=0;i<n;i++)
	{
		if (S[i]!=S[i+1] ) {	kq[k]=S[i];k++;}
	}
	puts(kq);
}
