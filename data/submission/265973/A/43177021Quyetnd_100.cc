<<<<<<< Updated upstream
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	int n,k,ans = 0, s =0;
	cin>>n>>k;
	int A[n];
	for(int i =0; i<n;i++){
		cin>>A[i];
	}
	for(int i = 0; i<n;i++){
		s=A[i];
		if (s % k == 0){
			ans = ans + 1;
		}
		for(int j = i+1 ; j < n && i!= j ; j++){
			s = s + A[j];
			if (s % k == 0){
				ans= ans +1;
			}
		}
		s=0;
	}
	cout<<ans;
}
=======
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	int n,k,ans = 0, s =0;
	cin>>n>>k;
	int A[n];
	for(int i =0; i<n;i++){
		cin>>A[i];
	}
	for(int i = 0; i<n;i++){
		s=A[i];
		if (s % k == 0){
			ans = ans + 1;
		}
		for(int j = i+1 ; j < n && i!= j ; j++){
			s = s + A[j];
			if (s % k == 0){
				ans= ans +1;
			}
		}
		s=0;
	}
	cout<<ans;
}
>>>>>>> Stashed changes
