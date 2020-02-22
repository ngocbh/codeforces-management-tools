<<<<<<< Updated upstream
#include<iostream>
#include<math.h>
#include <algorithm>
using namespace std;
typedef struct mouseHouse{
	int x;
	int y;
	int numb;
} mouseHouse;

mouseHouse nhaChuot[20001];
int d;
int n;
int a[101][101];
int main(){
	cin>>d>>n;
	for(int i=1;i<=n;i++){
		cin>>nhaChuot[i].x;
		cin>>nhaChuot[i].y;
		cin>>nhaChuot[i].numb;
	}
	//tinh so luong chuot co the giet vao 1 mang
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			int cnt = 0;
			for(int k=1;k<=n;k++){
				int X = nhaChuot[k].x;
				int Y = nhaChuot[k].y;
				int NUMB = nhaChuot[k].numb;
				if(max( abs(X-i) , abs(Y-j) ) <= d) cnt+=NUMB;
			}
			a[i][j] = cnt;
		}
	}
	//duyet tat ca cac o co the giet chuot
	int MAX = 0;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if( MAX < a[i][j] ) MAX = a[i][j];
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if( a[i][j] == MAX){
				cout<<i<<" "<<j<<" "<<a[i][j];
				return 0;
			}
		}
	}
=======
#include<iostream>
#include<math.h>
#include <algorithm>
using namespace std;
typedef struct mouseHouse{
	int x;
	int y;
	int numb;
} mouseHouse;

mouseHouse nhaChuot[20001];
int d;
int n;
int a[101][101];
int main(){
	cin>>d>>n;
	for(int i=1;i<=n;i++){
		cin>>nhaChuot[i].x;
		cin>>nhaChuot[i].y;
		cin>>nhaChuot[i].numb;
	}
	//tinh so luong chuot co the giet vao 1 mang
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			int cnt = 0;
			for(int k=1;k<=n;k++){
				int X = nhaChuot[k].x;
				int Y = nhaChuot[k].y;
				int NUMB = nhaChuot[k].numb;
				if(max( abs(X-i) , abs(Y-j) ) <= d) cnt+=NUMB;
			}
			a[i][j] = cnt;
		}
	}
	//duyet tat ca cac o co the giet chuot
	int MAX = 0;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if( MAX < a[i][j] ) MAX = a[i][j];
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if( a[i][j] == MAX){
				cout<<i<<" "<<j<<" "<<a[i][j];
				return 0;
			}
		}
	}
>>>>>>> Stashed changes
}