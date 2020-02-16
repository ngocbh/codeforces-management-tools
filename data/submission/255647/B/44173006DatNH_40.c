#include<stdio.h>
int main()
{
	int k,n;
	int a[1000000];
	scanf("%d",&n);
	for(k=0;k<n;k++)
	scanf("%d",&a[k]);
	int j,i, max1=0,max2=0,max3=0,max4=0,maxlen=0,maxxuong=0;
	for(i=0;i<n-1;i++)
	{
		j=i;
		if(a[i+1]>a[i]){
		while((i<n-1)&&(a[i+1]>a[i]))
		{
			i++;
		}
		max1=i-j;
		if(max1>max2) max3=max2;
		else max3=max1;
		if(maxxuong<max3) maxxuong=max3;}
		j=i;
		if(a[i+1]<a[i]){
		while((i<n-1)&&(a[i+1]<a[i]))
		{
			i++;
		}
		max2=i-j;
		if(max1>max2) max4=max2;
		else max4=max1;
		if(maxlen<max4) maxlen=max4;}
		if(a[i+1]==a[i]){
		while((i<n-1)&&(a[i+1]=a[i]))
		{
			i++;
		}max1=0; max2=0;
	}
	} printf("%d %d",maxlen,maxxuong);
}