#include<stdio.h>
int duyet(int a[10000],int N,int K){
	int i,j,q;
	for(i=0;i<N-1;i++){
		int sum=0;
		for(j=i;j<N;j++){
			sum+=a[j];
			if(sum%K==0)
			q++;
		}
	}
	return q;
}
int main(){
	int i,N,K,a[10000];
	scanf("%d",&N);
	scanf("%d",&K);
	for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	int m=duyet(a,N,K);
	printf("%d",m);
	return 0;
}