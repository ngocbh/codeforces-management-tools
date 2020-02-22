<<<<<<< Updated upstream
#include<stdio.h>
#include<math.h>
int f=0,e=0,soluongmax=0;
void rat(int a[20000],int b[20000],int c[20000],int d,int n){
	int i,j,k;
	for(i=d;i<=100-d;i++){
		for(j=d;j<=100-d;j++){
			int soluong=0;
			for(k=0;k<n;k++){
				if((abs(a[k]-i)<=d)&&(abs(b[k]-j)<=d))
				soluong+=c[k];
			}
			if(soluong>=soluongmax){
				f=i;
				e=j;
				soluongmax=soluong;
			}
		}
	}
}
int main(){
	int i,d,n,a[20000],b[20000],c[20000];
	scanf("%d",&d);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&c[i]);
	}
	rat(a,b,c,d,n);
	printf("%d ",f);
	printf("%d ",e);
	printf("%d",soluongmax);
	return 0;
=======
#include<stdio.h>
#include<math.h>
int f=0,e=0,soluongmax=0;
void rat(int a[20000],int b[20000],int c[20000],int d,int n){
	int i,j,k;
	for(i=d;i<=100-d;i++){
		for(j=d;j<=100-d;j++){
			int soluong=0;
			for(k=0;k<n;k++){
				if((abs(a[k]-i)<=d)&&(abs(b[k]-j)<=d))
				soluong+=c[k];
			}
			if(soluong>=soluongmax){
				f=i;
				e=j;
				soluongmax=soluong;
			}
		}
	}
}
int main(){
	int i,d,n,a[20000],b[20000],c[20000];
	scanf("%d",&d);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&c[i]);
	}
	rat(a,b,c,d,n);
	printf("%d ",f);
	printf("%d ",e);
	printf("%d",soluongmax);
	return 0;
>>>>>>> Stashed changes
}