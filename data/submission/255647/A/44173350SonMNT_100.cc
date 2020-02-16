#include<stdio.h>
#include<string.h>
char a[150000]="",b[150000]="",c[150000]="";
int tim(int i){
	char n=a[i];
	int m;
	for(m=i+1;a[m]==n;m++);
	return m;
}
void xulyxau(int max){
	int k=0;
	for(int i=0;a[k]!='\0';i++){
		b[i]=a[k];
		k=tim(k);
	}
}
main(){
	gets(a);
	xulyxau(strlen(a));
	puts(b);
}