<<<<<<< Updated upstream
#include<bits/stdc++.h>

using namespace std;

#define MAX 100001

int P = pow(10,9) + 7;

int S1[MAX];
int S2[MAX];
int F[MAX];
int n;

int addmod(int a, int b){
	a = a % P;
	b = b % P;
	int tmp = P - a;
	if (tmp > b) return a + b;
	return b - tmp;
}
 
int mulmod(int a, int b){
	if (b == 1){
		return a%P;
	}
	if (a == 1){
		return b%P;
	}
	if (a>b){
		int tmp = a;
		a = b; 
		b = tmp;
	}
	int c = mulmod(a / 2, b);
	c  = addmod(c,c);
	if ((a%2) == 0) return c;
	else return addmod(c,b);
}

void input(){
	cin >> n;
}
void solve(){
	F[1] = 1;
	F[2] = 4;
	for (int  i = 3; i <= n; i++){
		F[i] = addmod(mulmod(F[i-1], 3), mulmod(2, F[i-2]));
	}
	cout << F[n] << endl;
}
int main(){
	input();
	solve();
	return 0;
=======
#include<bits/stdc++.h>

using namespace std;

#define MAX 100001

int P = pow(10,9) + 7;

int S1[MAX];
int S2[MAX];
int F[MAX];
int n;

int addmod(int a, int b){
	a = a % P;
	b = b % P;
	int tmp = P - a;
	if (tmp > b) return a + b;
	return b - tmp;
}
 
int mulmod(int a, int b){
	if (b == 1){
		return a%P;
	}
	if (a == 1){
		return b%P;
	}
	if (a>b){
		int tmp = a;
		a = b; 
		b = tmp;
	}
	int c = mulmod(a / 2, b);
	c  = addmod(c,c);
	if ((a%2) == 0) return c;
	else return addmod(c,b);
}

void input(){
	cin >> n;
}
void solve(){
	F[1] = 1;
	F[2] = 4;
	for (int  i = 3; i <= n; i++){
		F[i] = addmod(mulmod(F[i-1], 3), mulmod(2, F[i-2]));
	}
	cout << F[n] << endl;
}
int main(){
	input();
	solve();
	return 0;
>>>>>>> Stashed changes
}