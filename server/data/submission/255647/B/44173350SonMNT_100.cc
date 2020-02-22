#include<stdio.h>
int a[1000000],b[1000000],mindoi,minlung,len,xuong,n,kqdoi,kqlung;
int timdoi(int i){
	while(i<n-1){
		while(i<n-1&&a[i]==a[i+1]){
		i++;
		}
		len=0;
		while(i<n-1&&a[i]<a[i+1])	{
			i++;
			len++;
		}
		if(len>xuong){
		minlung=xuong;
		}
		else {
			minlung=len;
		}
		xuong=0;
	    while (i<n-1&&a[i]>a[i + 1])
			{
			i++;
			xuong++;
			
			}if(len>xuong){
		mindoi=xuong;
		}
		else {
			mindoi=len;
		}
		if(kqdoi<mindoi)kqdoi=mindoi;
		if(kqlung<minlung)kqlung=minlung;			
	}
		
	
}

main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
timdoi(0);
	printf("%d %d",kqdoi,kqlung);
		
}
