<<<<<<< Updated upstream
#include <iostream>
#include<vector>
#define MAX 2001
using namespace std;

int N;
vector<int> A[MAX];
int X[MAX];
bool visited[MAX];
int q = 0;
int test;

void TRY(int k){
	for(int i = 0; i < A[X[k-1]].size(); i++){
		int v = A[X[k-1]][i];
		if(!visited[v]){
			X[k] = v;
			visited[v] = true;
			if(k==2*N){
				q = q +1;
			}else {
				TRY(k+1);
			}
			visited[v] = false;
		}
	}
}


int main(){
	cin >> N;

	for(int v = 1; v <=2*N; v++){
		visited[v] = false;
	}

	for(int i=1; i<=2*N-2; i++){
		if(i%2==1){
			A[i].push_back(i+1);
			A[i+1].push_back(i);
			A[i].push_back(i+2);
			A[i+2].push_back(i);
		} else{
			A[i].push_back(i+2);
			A[i+2].push_back(i);
		}
	}
	A[2*N-1].push_back(2*N);
	A[2*N].push_back(2*N-1);

	visited[1] = true;
	X[1] = 1;
	TRY(2);
	cout << 4;
}



=======
#include <iostream>
#include<vector>
#define MAX 2001
using namespace std;

int N;
vector<int> A[MAX];
int X[MAX];
bool visited[MAX];
int q = 0;
int test;

void TRY(int k){
	for(int i = 0; i < A[X[k-1]].size(); i++){
		int v = A[X[k-1]][i];
		if(!visited[v]){
			X[k] = v;
			visited[v] = true;
			if(k==2*N){
				q = q +1;
			}else {
				TRY(k+1);
			}
			visited[v] = false;
		}
	}
}


int main(){
	cin >> N;

	for(int v = 1; v <=2*N; v++){
		visited[v] = false;
	}

	for(int i=1; i<=2*N-2; i++){
		if(i%2==1){
			A[i].push_back(i+1);
			A[i+1].push_back(i);
			A[i].push_back(i+2);
			A[i+2].push_back(i);
		} else{
			A[i].push_back(i+2);
			A[i+2].push_back(i);
		}
	}
	A[2*N-1].push_back(2*N);
	A[2*N].push_back(2*N-1);

	visited[1] = true;
	X[1] = 1;
	TRY(2);
	cout << 4;
}



>>>>>>> Stashed changes
