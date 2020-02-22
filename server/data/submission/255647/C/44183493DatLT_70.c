#include<stdlib.h>
#include<stdio.h>
 
 
int cmpfunc (const void * a, const void * b)
{
     return ( *(long int*)a - *(long int*)b );
}
 
int main()
{
	long int i, n;
	long int *work, *cus;
	long long min;
	scanf("%d",&n);
	work = (long int *)malloc((n)*sizeof(long int));
	cus = (long int *)malloc((n)*sizeof(long int));	
	for (i = 0; i < n ; i++)
	{
		scanf("%d", &work[i]);
	}
	for (i = 0; i < n ; i++)
	{
		scanf("%d", &cus[i]);
	}
	qsort(work,n,sizeof(long int),cmpfunc);
	qsort(cus,n,sizeof(long int),cmpfunc);
	min = 0;
	for (i = 0; i<n; i++)
	{
		min += (work[i]-cus[i])*(work[i]-cus[i]);
	}
	//Try(0);	
	printf("%d", min);
	return 0;
}