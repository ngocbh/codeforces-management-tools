#include<stdlib.h>
#include<stdio.h>
int min(int a, int b){
	if (a>b) return b;
	else return a; 
}
int max(int a, int b){
	if(a>b) return a;
	else return b;
}
int doi(int a[150000],int left,int right){
	int i; int j; int k,n1,kqcc,n=right-left+1;
	n1=0;
	int * dinhdoi= (int*)malloc(n*sizeof(int));
	for(j=left+1;j<right;j++){
		if(a[j]>a[j-1]&&a[j]>a[j+1]) {
		dinhdoi[n1]=j;
		n1++;
		}
	}
	if(n1==0) return 0;
	kqcc=0;
	for(j=0;j<n1;j++){
		i=dinhdoi[j]-1;
		k=dinhdoi[j]+1;
		while(i>right&&a[i]>a[i-1]) i--;
		while(k<left&&a[k]>a[k+1]) k++;
		kqcc=max(kqcc,min(dinhdoi[j]-i,k-dinhdoi[j]));
	}
	return kqcc;
}
int thunglung(int a[150000],int left,int right){
	int i; int j; int k,n1,kqcc,n=right-left+1;
	n1=0;
	int * dinhdoi= (int*) malloc(n*sizeof(int));
	for(j=left+1;j<right;j++){
		if(a[j]<a[j-1]&&a[j]<a[j+1]) {
		dinhdoi[n1]=j;
		n1++;
		}
	}
	if(n1==0) return 0;
	kqcc=0;
	for(j=0;j<n1;j++){
		i=dinhdoi[j]-1;
		k=dinhdoi[j]+1;
		while(i>right&&a[i]<a[i-1]) i--;
		while(k<left&&a[k]<a[k+1]) k++;
		kqcc=max(kqcc,min(dinhdoi[j]-i,k-dinhdoi[j]));
	}
	return kqcc;
}
int main(){
	int n,i;
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	printf("%d %d",thunglung(a,0,n-1),doi(a,0,n-1));
	return 0;
}