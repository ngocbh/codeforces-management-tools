/*
 *  Problem : rat_bf.cpp
 *  Description : 
 *  Created by ngocjr7 on [2020-01-15 18:37]	
*/

#include <bits/stdc++.h>

using namespace std;
const long N = 100 + 7;
const long INF = 1000000000 + 7;
const long MODULE = 1000000000 + 7;
typedef pair<int,int> ii;

int n, d;
int a[N][N];
int M = 100;
int main()
{
	// freopen("in.txt","r",stdin);

	cin >> d >> n;
	for (int i = 1; i <= n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		a[u][v] = c;
	}

	int ans = 0, ansi = -1, ansj = -1;
	for (int u = 1; u <= M; u++) 
		for (int v = 1; v <= M; v++) {
			int sum = 0;
			for (int i = max(u-d,1); i <= min(u+d,M); i++)
				for (int j = max(v-d,1); j <= min(v+d,M); j++) {
					sum += a[i][j];
				}
			if ( sum > ans ) {
				ans = sum;
				ansi = u;
				ansj = v;
			}
		}

	cout<< ansi << " " << ansj <<  " "  << ans <<  endl;
	return 0;
}
