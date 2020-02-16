#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char array[160000];
	long long i,n,j;
	fflush(stdin);
	gets(array);
	i = 0;
	n = strlen(array);
	while(1)
	{
		if(array[i]==array[i+1])
		{
			for(j = i; j<n; j++)
			{
				array[j] = array[j+1];
			}
			n--;
			i--;
		array[n] = '\0';
		};
		i++;
		if (i >= n) break;
	}
	for (i = 0;i<n; i++) printf("%c",array[i]);
	return 0;
}