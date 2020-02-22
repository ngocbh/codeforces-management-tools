#include<bits/stdc++.h>

using namespace std;

int N;
long long M[100000];
long long p = pow(10,9) + 7;
long long solve(int n)
{
	if(M[n] != -1)
		return M[n] % p;
	else{
		M[n] = 4 * solve(n - 1) - solve(n-2);
		if(M[n] >= p)
			M[n] = M[n] % p;
	}
	return M[n] % p;
}

int main()
{
	cin >> N;
	for(int i = 0; i <= N; i++)
	{
		M[i] = -1;
	}
	M[0] = 0;
	M[1] = 1;
	long long res = solve(N);
	cout << M[N] % p;
}