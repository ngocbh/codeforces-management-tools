<<<<<<< Updated upstream
#include<iostream>
using namespace std;
int n,K;
int a[10002];
long long dem=0;
int main(){
	cin>>n>>K;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		int j=1;
		while(i+j-1<=n){
			int sum=0;
			for(int k=j;k<=j+i-1;k++){
				sum+=a[k];
			}
			if(sum%K==0) dem++;
			j++;
		}
	}
	cout<<dem;
=======
#include<iostream>
using namespace std;
int n,K;
int a[10002];
long long dem=0;
int main(){
	cin>>n>>K;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		int j=1;
		while(i+j-1<=n){
			int sum=0;
			for(int k=j;k<=j+i-1;k++){
				sum+=a[k];
			}
			if(sum%K==0) dem++;
			j++;
		}
	}
	cout<<dem;
>>>>>>> Stashed changes
}