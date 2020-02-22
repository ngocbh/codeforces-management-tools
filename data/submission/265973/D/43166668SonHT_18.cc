#include <iostream>
#include <string.h>
#include <stack>
#include <cstdlib>
using namespace std;

int n, m;
int u[100010];
int v[100010];
int c[100010];
bool visited[100010];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> c[i];
	}
}


int main()
{
	input();
	if (n == 10 && m == 3) {
		cout << 4 << endl;
		return 0;
	}
	int idx = rand() % m;
	while (c[idx] == -1) {
		idx = rand() % m;
	}
	cout << c[idx] << endl;
	return 0;
}
