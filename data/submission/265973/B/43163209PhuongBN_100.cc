#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

int getMax(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int getMin(int a, int b){
	if(a < b)
		return a;
	else 
		return b;
}

int main(){
	int grid[101][101];
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			grid[i][j] = 0;
		}
	}
	int d, h;
	cin >> d >> h;
	for(int i = 0; i < h; i++){
		int x, y, v;
		cin >> x >> y >> v;
		grid[x][y] = v;
	}
	int arr[3];
	int max = 0;
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			int total = 0;
			for(int k = getMax(i-d, 0); k <= getMin(i+d, 100); k++){
				for(int m = getMax(j-d, 0); m <= getMin(j+d, 100); m++){
					total += grid[k][m];				
				}
			}
			if(total > max){
				max = total;
				arr[0] = i;
				arr[1] = j;
				arr[2] = max;}		
		}
	}
	
	cout << arr[0] << " " << arr[1] << " " << arr[2];
	
	
	
}