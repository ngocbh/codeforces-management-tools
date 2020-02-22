<<<<<<< Updated upstream
#include<iostream>
using namespace std;
int main(){
	int d;
	int n;
	cin>>d>>n;
	int X = 0;
	int Y = 0;
	int kq = 0;
	int a[105][105];
	for(int i=0; i<102; i++)
		for(int j=0; j<102; j++)
			a[i][j]=0;
	for(int i=0; i<n; i++){
		int x,y,S;
		cin>>x>>y>>S;
		a[x][y]=S;
	}
	for(int i=0; i<101; i++){
		for(int j=0; j<101; j++){
			int x1,y1,z1,t1;
			int sum = 0;
			if(i-d>=0) x1 = i-d;
			else x1 = 0;
			if(j-d>=0) y1 = j-d;
			else y1 = 0;
			if(i+d<=100) z1 = i+d;
			else z1 = 100;
			if(j+d<=100) t1 = j+d;
			else t1 = 100;
			for(int x=x1; x<=z1; x++){
				for(int y=y1; y<=t1; y++){				
						sum = sum + a[x][y];
					}
			}
			if(kq<sum){
			kq = sum;
			X = i;Y = j;
			}		
		}
	}
	cout<<X<<" "<<Y<<" "<<kq;
	
=======
#include<iostream>
using namespace std;
int main(){
	int d;
	int n;
	cin>>d>>n;
	int X = 0;
	int Y = 0;
	int kq = 0;
	int a[105][105];
	for(int i=0; i<102; i++)
		for(int j=0; j<102; j++)
			a[i][j]=0;
	for(int i=0; i<n; i++){
		int x,y,S;
		cin>>x>>y>>S;
		a[x][y]=S;
	}
	for(int i=0; i<101; i++){
		for(int j=0; j<101; j++){
			int x1,y1,z1,t1;
			int sum = 0;
			if(i-d>=0) x1 = i-d;
			else x1 = 0;
			if(j-d>=0) y1 = j-d;
			else y1 = 0;
			if(i+d<=100) z1 = i+d;
			else z1 = 100;
			if(j+d<=100) t1 = j+d;
			else t1 = 100;
			for(int x=x1; x<=z1; x++){
				for(int y=y1; y<=t1; y++){				
						sum = sum + a[x][y];
					}
			}
			if(kq<sum){
			kq = sum;
			X = i;Y = j;
			}		
		}
	}
	cout<<X<<" "<<Y<<" "<<kq;
	
>>>>>>> Stashed changes
}