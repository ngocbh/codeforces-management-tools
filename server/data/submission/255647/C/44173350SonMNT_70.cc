#include<stdio.h>

/*oid swap(int &a,int &b){
	int tg=a;
	a=b;
	b=tg;  
}*/
int divise(int a[], int left, int right ){
	float x=a[left];
	int i=left;
	int j=right;
	while(true){
		i++;
		while((i<=right)&&(a[i]<x))i++;
		while((j>=left)&&(a[j]>x))j--;
		if(i>=j)break;
		//swap(a[i],a[j]);
		int tg=a[i];
		a[i]=a[j];
		a[j]=tg;
	}
	//swap(a[j],a[left]);
	int tg2=a[j];
	a[j]=a[left];
	a[left]=tg2;
	return j;
}
void quicksort(int a[],int left, int right){
	float x;
	if(left<right){
	x=divise(a,left,right);quicksort(a,x+1,right);
	quicksort(a,left,x-1);
	
	}
}
/*int tinh(int a[],int b[],int n){
	int sum=0;
	for(int i = 0 ;i<n; i++){
		int x=(a[i]-b[i]);
		sum+=x*x;
	}
	return sum;
}*/

main(){
long n;
	scanf("%d",&n);
	int a[30000],b[30000];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	quicksort(a,0,n-1);
	quicksort(b,0,n-1);
	unsigned long long sum=0;
	for(int i = 0 ;i<n; i++){
		int x=(a[i]-b[i]);
		sum+=x*x;
	}

	printf("%d",sum);
	
}
