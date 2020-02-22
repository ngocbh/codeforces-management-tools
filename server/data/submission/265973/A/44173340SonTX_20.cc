#include <iostream>
#include <math.h>
using namespace std;




int main(){
	int n,k;
	cin >> n>> k;
	
	int a[n] ={0};
	for(int i = 0;i<n; i++){
		cin >>a[i];
	}
	int dem=0;
	for(int i =0; i<n;i++){
		int tong =0;
		for(int j =i; j<n ; j++){
			tong +=a[i];
			if (a[i]%k ==0) dem++;
		}
	}
	cout <<dem;
}