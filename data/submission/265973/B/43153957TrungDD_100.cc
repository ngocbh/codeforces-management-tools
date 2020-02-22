<<<<<<< Updated upstream
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

int n, d;
int c[110][110];
int x, y, co;
int xr, yr, temp, res=0;

int sol(int k, int t){
	int rt=0;
	for(int i = max(0, k-d); i <= min(100, k+d); i++)
		for(int j = max(0, t-d); j <= min(100, t+d); j++){
			if(max(abs(i-k), abs(j-t)) <= d){
				rt+=c[i][j];
			}
		}
	return rt;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> d >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> co;
		c[x][y] = co;
	}
	
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++){
			temp = sol(i, j);
			if(res < temp){
				res = temp;
				xr = i; yr = j;
			}
		}
	
	cout << xr << " " << yr << " " << res;
	
	return 0;
}


=======
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

int n, d;
int c[110][110];
int x, y, co;
int xr, yr, temp, res=0;

int sol(int k, int t){
	int rt=0;
	for(int i = max(0, k-d); i <= min(100, k+d); i++)
		for(int j = max(0, t-d); j <= min(100, t+d); j++){
			if(max(abs(i-k), abs(j-t)) <= d){
				rt+=c[i][j];
			}
		}
	return rt;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> d >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> co;
		c[x][y] = co;
	}
	
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++){
			temp = sol(i, j);
			if(res < temp){
				res = temp;
				xr = i; yr = j;
			}
		}
	
	cout << xr << " " << yr << " " << res;
	
	return 0;
}


>>>>>>> Stashed changes
