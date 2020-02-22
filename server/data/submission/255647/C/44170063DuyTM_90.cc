#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long res = 0;
	for(int i = 0; i < n; i++) res += (a[i] - b[i]) * (a[i] - b[i]);
	cout << res << endl;
}
