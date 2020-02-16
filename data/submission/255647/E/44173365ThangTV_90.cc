#include<iostream>
using namespace std;
int BS[10], H[10], L[10], N, M, GK[20], cost = 100000000;
int time[10], list[10][20], nob[10];
int listkq[10][20], nobkq[10];
void kb(int bn, int need) {
	if (bn == N)
	{
		if (need < cost) cost = need;
		for (int i = 0; i < M; i++)
		{
			nobkq[i] = nob[i];
			for (int j = 0; j < nob[i]; j++)
				listkq[i][j] = list[i][j]+1;
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			if ((time[i] + GK[bn]) <= H[i])
			{
				int phi;
				list[i][nob[i]] = bn;
				nob[i]++;
				time[i] += GK[bn];
				phi = L[i] * GK[bn];
				need +=phi;
				if (need < cost) kb(bn + 1, need);
				time[i] -= GK[bn];
				need -= phi;
				nob[i]--;
			}
		}
	}
}
int main() {
	cin >> M;
	int i, j;
	for (i = 0; i < M; i++)
		cin >> H[i];
	for (i = 0; i < M; i++)
	{
		cin >> L[i];
		time[i] = 0;
		nob[i] = 0;
	}
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> GK[i];
	kb(0, 0);
	if (cost != 100000000) {
		cout << cost << endl;
		for (int i = 0; i < M; i++)
		{
			cout << nobkq[i] << " ";
			for (int j = 0; j < nobkq[i]; j++)
				cout << listkq[i][j] << " ";
			cout << endl;
		}
	}
	else cout << -1;
	//system("pause");
}