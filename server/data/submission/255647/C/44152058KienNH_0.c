#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	scanf("%d",&n);
	int a[n];
	int s[n];
	int i, j = 0;
	gets(a);
	strlen(s) = strlen(a);	gets(s);
	int x = 1000;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (abs(a[i] - a[j]) < x) {x= abs(a[i]-a[j])};
		}
		y = x * x;
	puts(y);
}