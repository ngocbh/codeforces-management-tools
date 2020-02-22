#include<stdio.h>
int a[10000],f[10000],s=0,g[10000],i,h;
void xuly(int n,int k){
	for(i=0;i<n;i++){
		if(f[i+1]%k!=0){
			h = i + 1;
			for (int j = 0; j < i; j++) {
				f[h] -= a[j];
				if (f[h] % k == 0) g[h]++;
			}
		}
		else{
				g[i+1]=s+1;
			}
		 s+= g[i + 1];
		}
}
main(){
	int n,k;
	
	scanf("%d",&n);
	scanf("%d",&k);
	for( i = 0; i<n ;i++){
		scanf("%d",&a[i]);
		g[i]=0;
		f[i+1]=f[i]+a[i];		
	}
	xuly(n,k);
	
	printf("%d",s);
}
