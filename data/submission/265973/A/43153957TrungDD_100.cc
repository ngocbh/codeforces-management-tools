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

int n, k;
int a[10010], sum[10010];

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	cin >> a[0]; sum[0] = a[0];
	for(int i = 1; i < n; i++){
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	
	long long res = 0;
	
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if((sum[j]-sum[i]) % k == 0) res++;
		}
	}
	for(int i = 0; i < n; i++) if(sum[i] % k == 0) res++;
	cout << res << endl;
	
	return 0;
}


