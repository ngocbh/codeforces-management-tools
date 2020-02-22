<<<<<<< Updated upstream
/*
inputCopy
2
outputCopy
4
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mod = 1000000007;
long long f[1000001];
void solve(int n){
	f[1] = 1;
	f[2] = 4;
	for(int i=3;i<=n;i++){
		long long x = f[i-2];
		long long y = f[i-1] * 4;
		f[i] = (y-x)%mod;
	}	
}

int main(){
	//input
	int n;cin>>n;
	//handle	
	solve(n);
	//show output
	cout<<f[n];

	return 0;
}

=======
/*
inputCopy
2
outputCopy
4
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mod = 1000000007;
long long f[1000001];
void solve(int n){
	f[1] = 1;
	f[2] = 4;
	for(int i=3;i<=n;i++){
		long long x = f[i-2];
		long long y = f[i-1] * 4;
		f[i] = (y-x)%mod;
	}	
}

int main(){
	//input
	int n;cin>>n;
	//handle	
	solve(n);
	//show output
	cout<<f[n];

	return 0;
}

>>>>>>> Stashed changes
