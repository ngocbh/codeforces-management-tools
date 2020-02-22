#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int d ,n ,A[105][105] = {0} , B[105][105] = {0}, d_max = 0, t, s;

int main(){
	cin>>d>>n;
//	for(int i =0; i<105;i++){
//		for(int j =0; j < 105;j++){
//			A[i][j] =0;
//		//	B[i][j] = 0;
//		}
//	}
	for(int i =0; i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		A[a][b] = c;
		for(int q = -d; q <= d; q++){
			for(int p = -d; p <= d; p++){
				B[a+q][b+p] = B[a+q][b+p] +A[a][b] ;
				if(B[a+q][b+p] > d_max){
					d_max = B[a+q][b+p];
					t = a+q;
					s = b+p;
				}
			}
		}
	}

	cout<<t<<" "<<s<<" "<<d_max;
}
