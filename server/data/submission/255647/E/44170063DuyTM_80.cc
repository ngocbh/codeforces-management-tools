#include<bits/stdc++.h>

using namespace std;

int res = INT_MAX;
vector<vector<int>> list_res;


void bt(int pi, vector<int> const &pat, vector<int> &time, vector<int> const &cost, int cur, vector<vector<int>> &pat_list)
{
	if(cur >= res) return;
	if(pi == pat.size())
	{
		if(cur < res)
		{
			res = cur;
			list_res = pat_list;
		}
		return;
	}
	for(int i = 0; i < time.size(); i++)
	{
		if(time[i] >= pat[pi])
		{
			time[i] -= pat[pi];
			pat_list[i].push_back(pi);
			bt(pi + 1, pat, time, cost, cur + cost[i] * pat[pi], pat_list);
			pat_list[i].pop_back();
			time[i] += pat[pi];
		}
	}

}

int main()
{
	int m;
	cin >> m;
	vector<int> time(m);
	vector<int> cost(m);
	for(int i = 0; i < m; i++) cin >> time[i];
	for(int i = 0; i < m; i++)	cin >> cost[i];
	int n;
	cin >> n;
	vector<int> pat(n);
	vector<vector<int>> pat_list(m);
	for(int i = 0; i < n; i++) cin >> pat[i];
	bt(0, pat, time, cost, 0, pat_list);
	if(res != INT_MAX)
	{
		cout << res << endl;
		for(int i = 0; i < m; i++)
		{
			cout << list_res[i].size() << " ";
			for(int j = 0; j < list_res[i].size(); j++) cout << list_res[i][j] + 1 << " ";
			cout << endl;
		}
	}
	else cout << -1 << endl;
}
