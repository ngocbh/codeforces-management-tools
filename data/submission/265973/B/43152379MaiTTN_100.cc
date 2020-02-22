#include<iostream>
using namespace std;
#define max_n 102
int d;
int n;
int a[max_n][max_n];
int sum=0;
int x0=0,y0=0;
int main(){
	cin>>d>>n;
	for(int i=0; i<max_n; i++)
		for(int j=0; j<max_n; j++)
			a[i][j]=0;
	for(int i=1; i<=n; i++){
		int x,y,s;
		cin>>x>>y>>s;
		a[x][y]=s;
	}
	for(int i=0; i<=100; i++){
		for(int j=0; j<=100; j++){
			int tong=0;
			int a0,b0,c0,d0;
			if(i-d>=0)a0=i-d;else a0=0;
			if(i+d<=100) c0=i+d;else c0=100;
			if(j-d>=0) b0=j-d;else b0=0;
			if(j+d<=100) d0=j+d;else d0=100;
			for(int x=a0; x<=c0; x++){
				for(int y=b0; y<=d0;y++){				
						tong+=a[x][y];
					}
			}
			if(tong>sum){sum=tong;x0=i;y0=j;}
			//else if(tong==sum){ if(i<x0){ x0=i;y0=j;} else if(i==x0){if(j<y0) y0=j;}}			
		}
	}
	cout<<x0<<" "<<y0<<" "<<sum;
	
}