#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[],int low,int high)
{
	int pivot=a[high];
	int left=low;
	int right=high-1;
	while(1)
	{
		while((a[left]<pivot)&&(left<=right)) left++;
		while((a[right]>pivot)&&(right>=left)) right--;
		if(left>=right) break;
		swap(&a[left],&a[right]);
		left++;
		right--;
	}swap(&a[left],&a[high]);
	return left;
}
void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int m=partition(a,low,high);
		quicksort(a,low,m-1);
		quicksort(a,m+1,high);
	}
}
int main()
{
	int n,i;
	unsigned long long s=0;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	quicksort(a,0,n-1);
	quicksort(b,0,n-1);
	for(i=0;i<n;i++)
	s+=((a[i]-b[i])*(a[i]-b[i]));
	printf("%d",s);
	return 0;
}