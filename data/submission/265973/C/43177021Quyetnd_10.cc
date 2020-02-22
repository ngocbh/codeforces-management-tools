<<<<<<< Updated upstream
#include<bits/stdc++.h>
#define Max 50

using namespace std;

int n,ans=0;
int b[Max];
int e[Max];
int r[Max];
int p[Max];
int x[Max];
int visit[Max];

int find(int x){
	if (x != p[x]){
		p[x] = find(p[x]);
	}
	return p[x];
}

int make_set(int x){
	
		p[x] = x;
		r[x] = 0;
	
}

void merger(int x, int y){
	int px = find(x);
	int py = find(y);
	if (r[px] < r[py]){
		p[px] = py;
	}else{
		p[py] = px;
		if (r[x] == r[y]){
			r[px]++;
		}
	}
}

bool checkSolution(){
	for(int i =1; i<=2*n;i++){
		make_set(i);
	}
	for(int i = 1; i < 2*n-1;i++){		//cay khug n dinh co n-1 canh
		if (find(b[x[i]]) == find(e[x[i]])){
			return false;
		}
		merger(b[x[i]], e[x[i]]);
	}
	return true;
}

void Try(int k){
	for(int v = x[k-1] +1 ; v<=3*n-2;v++){
		if(visit[v]){
			x[k] = v;
			visit[v] = 0;
			if (k == 2*n-1){
				if(checkSolution()){
					ans++;
				}
			}else{
				Try(k+1);
			}
			visit[v] = 1;	
		}
	}
}

int main(){
	cin>>n;
	int z = 1;
	for(int i =1 ; i<=3*n-2 ; i=i+3 ){
		b[i] = z;
		e[i] = z+1;
		b[i+1] = z;
		e[i+1] = z+2;
		b[i+2] = z+1;
		e[i+2] = z+3;
		z=z+2;
	}

	for(int i =1; i<=3*n-2;i++){
	//	cout<<b[i]<<" "<<e[i];
		visit[i] = 1;
	//	cout<<"\n";
	}
	x[0] = -1;
	Try(1);
	cout<<ans;
}
=======
#include<bits/stdc++.h>
#define Max 50

using namespace std;

int n,ans=0;
int b[Max];
int e[Max];
int r[Max];
int p[Max];
int x[Max];
int visit[Max];

int find(int x){
	if (x != p[x]){
		p[x] = find(p[x]);
	}
	return p[x];
}

int make_set(int x){
	
		p[x] = x;
		r[x] = 0;
	
}

void merger(int x, int y){
	int px = find(x);
	int py = find(y);
	if (r[px] < r[py]){
		p[px] = py;
	}else{
		p[py] = px;
		if (r[x] == r[y]){
			r[px]++;
		}
	}
}

bool checkSolution(){
	for(int i =1; i<=2*n;i++){
		make_set(i);
	}
	for(int i = 1; i < 2*n-1;i++){		//cay khug n dinh co n-1 canh
		if (find(b[x[i]]) == find(e[x[i]])){
			return false;
		}
		merger(b[x[i]], e[x[i]]);
	}
	return true;
}

void Try(int k){
	for(int v = x[k-1] +1 ; v<=3*n-2;v++){
		if(visit[v]){
			x[k] = v;
			visit[v] = 0;
			if (k == 2*n-1){
				if(checkSolution()){
					ans++;
				}
			}else{
				Try(k+1);
			}
			visit[v] = 1;	
		}
	}
}

int main(){
	cin>>n;
	int z = 1;
	for(int i =1 ; i<=3*n-2 ; i=i+3 ){
		b[i] = z;
		e[i] = z+1;
		b[i+1] = z;
		e[i+1] = z+2;
		b[i+2] = z+1;
		e[i+2] = z+3;
		z=z+2;
	}

	for(int i =1; i<=3*n-2;i++){
	//	cout<<b[i]<<" "<<e[i];
		visit[i] = 1;
	//	cout<<"\n";
	}
	x[0] = -1;
	Try(1);
	cout<<ans;
}
>>>>>>> Stashed changes
