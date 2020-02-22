#include<bits/stdc++.h>

using namespace std;

int N, K;
int M[100000];

void input()
{
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		cin >> M[i];
	}
}

int solve(int s, int f)
{
	int count = 0;
	for(int i = s; i <= f; i++)
	{
		count += M[i];
	}
	if(count % K == 0)
		return 1;
	else
		return 0;
}

int main()
{
	input();
	int count = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = i; j< N; j++)
		{
			count += solve(i, j);
		}
	}
	cout << count;
	return 0;
}