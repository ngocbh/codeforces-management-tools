<<<<<<< Updated upstream
#include<stdio.h>
#include<iostream>
#define MAX 1000
using namespace std;
int N, K;
int a[MAX];
int main(){
	cin>>N>>K;
	for(int i=0; i< N; i++){
	cin>>a[i];
	}
	int Q=0;
	int sum= 0; 
	for (int i = 0; i < N; i++) {
		for( int j=1; j<N;j++){sum = a[i]+a[j];
		if(sum%K==0){
	Q++;
		}}}			
	 cout<<Q;
=======
#include<stdio.h>
#include<iostream>
#define MAX 1000
using namespace std;
int N, K;
int a[MAX];
int main(){
	cin>>N>>K;
	for(int i=0; i< N; i++){
	cin>>a[i];
	}
	int Q=0;
	int sum= 0; 
	for (int i = 0; i < N; i++) {
		for( int j=1; j<N;j++){sum = a[i]+a[j];
		if(sum%K==0){
	Q++;
		}}}			
	 cout<<Q;
>>>>>>> Stashed changes
	return 0;}