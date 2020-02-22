#include<stdio.h>
#include<conio.h>
#include<string.h>
int main() {
	char s[150000],kq[150000],last='\n';
	int l,i,index=0;
	gets(s);
	i = 0;
	l = strlen(s);
	while (i != l)
	{
		if (s[i] != last)
		{
			last = s[i];
			kq[index] = s[i];
			i++;
			index++;
		}
		else
		{
			i++;
		}
	}
	kq[index] = '\0';
	puts(kq);
	//_getch();
}