#include "stdio.h"
#include "math.h"
#define N 100001
#define P 1000000007

int n;
long a[N];

void input(){
	scanf("%d", &n);
}

long addmod(long a, long b){
    a = a%P;
    b = b%P;
    int tmp = P - a;
    if(tmp > b) return a+b;
    else return b - tmp;
}
long mulmod(long a, long b){
	if(a == 1) return b%P;
	if(b == 1) return a%P;
	if(a<b){  
		int tmp = a;
		a = b;
		b = tmp;
	}
	//b<a
	long rs = mulmod(a,b/2);
	rs = addmod(rs,rs);
	if(b%2==0) return rs;
	else return addmod(a,rs);
}
long expmod(long a,long b){
	if(b==0) return 1;
	if(b == 1) return a%P;
	long rs = expmod(a,b/2);
	rs = mulmod(rs,rs);
	if(b%2==0) return rs;
	else return mulmod(a,rs);
}
int main(){
	input();
	a[1] = 1;
	a[2] = 4;
	
	for(int i = 3; i <= n; i++){
		long mu = expmod(3, i-3);
//		printf("%d %d %i\n",mu, a[i-1], i);
		a[i] = mulmod(a[i-1],4) - mulmod(mu,4);
//		printf("%d %d\n", i, a[i]);
	}
	printf("%d", a[n]);
}