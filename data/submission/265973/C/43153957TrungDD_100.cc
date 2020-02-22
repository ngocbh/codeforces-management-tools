#include <bits/stdc++.h>

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LLD long long
#define VI vector < int >
#define PII pair < int , int >
#define MAX 1000000000

using namespace std;

int n;
long long res;
long long r[100010];
long long klt[100010];

long long sol(int n){
	if(n == 1) return 1;
	else if(n==2) return 4;
	else{
		r[2] = 4;
		klt[2] = 3;
		for(int i = 3; i <= n; i++){
			r[i] = (3*r[i-1] % MOD + klt[i-1]) % MOD;
			klt[i] = (klt[i-1] + 2*r[i-1] % MOD) % MOD;
		}
		return r[n];
	}
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	res = sol(n);
	cout << res << endl;
	
	return 0;
}


