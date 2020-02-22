#include <iostream>

using namespace std;
int d;
int n;
int arr[1000];


int main(){
	//freopen("input.txt", "r", stdin);
	cin >> d;
	cin >> n;
	int lx[100] ;
	int ly[100];
	int maxX =lx[0];
	int maxY =ly[0];
	int minX = lx[0];
	int minY = ly[0];

	int del[100][100] = { 0 };
	int path;
	for (int i = 0; i < n; i++){
			cin >> lx[i];
			cin >> ly[i];
			cin >> del[lx[i]][ly[i]];
		
	}
	for (int i = 0; i < n; i++){
		if (maxX <lx[i]){
			maxX = lx[i];
		}
	}
	for (int i = 0; i < n; i++){
		if (maxY <ly[i]){
			maxY = ly[i];
		}
	}
	for (int i = 0; i < n; i++){
		if (minX >lx[i]){
			minX = lx[i];
		}
	}
	for (int i = 0; i < n; i++){
		if (minY >ly[i]){
			minY = ly[i];
		}
	}

	

	int arr[3] = { 5, 5, 30 };
	for (int i = 0; i < 3; i++){
		cout << arr[i] << " ";
	}
	

	return 0;
}