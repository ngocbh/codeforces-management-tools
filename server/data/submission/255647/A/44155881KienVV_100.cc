#include<stdio.h>
#include<conio.h>
#include<string.h>
int main() {
	char a[150000],b[150000],last='\n';
	int l,i,j=0;
	gets(a);
	i = 0;
	l = strlen(a);
	while (i != l)
	{
		if (a[i] != last)
		{
			last = a[i];
			b[j] = a[i];
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	b[j] = '\0';
	puts(b);
	//_getch();
}