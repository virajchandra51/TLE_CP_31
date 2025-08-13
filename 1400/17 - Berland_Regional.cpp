#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<int> u(n), s(n);
	for (int i = 0; i < n; i++)	cin >> u[i];
	for (int i = 0; i < n; i++) cin >> s[i];
	
	vector<vector<int>> skills(n); // Total O(n) space

	for (int i = 0; i < n; i++) //O(n)
	{
		skills[u[i] - 1].push_back(s[i]);
	}

	for (auto &v : skills) //Total O(nlogn)
	{
		sort(v.begin(), v.end());
	}

	vector<vector<long long>> pre(n, vector<long long>(1, 0));
	for (int i = 0; i < n; i++) //Total O(n) time
	{
		for (int j = 0; j < skills[i].size(); j++)
		{
			pre[i].push_back(pre[i].back() + skills[i][j]);
		}
	}

	vector<long long> ans(n + 1); // O(n) space
	for (int i = 0; i < n; i++) // Total O(n) time
	{
		int nums = skills[i].size();
		for (int k = 1; k <= nums; k++)
		{
			ans[k] += pre[i].back() - pre[i][nums % k];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << ' ';
	}

	cout << '\n';
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--)
	{
		solve();
	}
}

// TC: O(nlogn)
// SC: O(n)