<<<<<<< Updated upstream
#include<bits/stdc++.h>
#define MAX 110
using namespace std;

int d;
int n;
int a[20000];
int b[20000];
int c[20000];


void input(){
	cin>>d>>n;
	for (int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	
		
	
}
void rat(){
	int rat = 0;
	
	int x; 
	int y;
	for (int i = 0; i<100; i++){
		for (int j = 0; j<100; j++){
			int sum  = 0;
			for (int k = 0; k<n;k++){
			if (c[k]>0){
				int dx = 0;
				int dy = 0;
				dx = abs(i-a[k]);
				dy = abs(j - b[k]);
				if ((max(dx,dy)<=d)){
					sum+=c[k];
					
				}
			}
			}
			if (sum> rat){
				rat = sum;
				x= i;
				y=j;
			}
	}
	}
	cout<<x <<" " <<  y<<" "<<rat;
	
}
int main(){
	input();
	rat();
=======
#include<bits/stdc++.h>
#define MAX 110
using namespace std;

int d;
int n;
int a[20000];
int b[20000];
int c[20000];


void input(){
	cin>>d>>n;
	for (int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	
		
	
}
void rat(){
	int rat = 0;
	
	int x; 
	int y;
	for (int i = 0; i<100; i++){
		for (int j = 0; j<100; j++){
			int sum  = 0;
			for (int k = 0; k<n;k++){
			if (c[k]>0){
				int dx = 0;
				int dy = 0;
				dx = abs(i-a[k]);
				dy = abs(j - b[k]);
				if ((max(dx,dy)<=d)){
					sum+=c[k];
					
				}
			}
			}
			if (sum> rat){
				rat = sum;
				x= i;
				y=j;
			}
	}
	}
	cout<<x <<" " <<  y<<" "<<rat;
	
}
int main(){
	input();
	rat();
>>>>>>> Stashed changes
}