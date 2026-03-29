#include <bits/stdc++.h>
using namespace std;

const int MAX = 2003;

bool good = true;
int p[MAX], c[MAX];
vector<int> adj[MAX];



vector<pair<int, int>> dfs(int v, int p) {

	vector<pair<int, int>> res;
	
	for (auto u : adj[v]) {
		if (u != p) {
			auto vec = dfs(u, v);
			for (auto i : vec)
				res.push_back(i);
		}
	}
	sort(res.begin(), res.end());

	if (c[v] > res.size()) {
		good = false;
		res.push_back({v, v});
		return res;
	}

	if (c[v] == 0) {
		if (res.empty()) res.push_back({v, v});
		else res.push_back({res[0].first - 1, v});
	} else {
		int val = res[c[v] - 1].first + 1;
		for (int i = c[v]; i < res.size(); i++) {
			res[i].first += 2;
		}
		res.push_back({val, v});
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int s = -1;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
		adj[p[i]].push_back(i);
		if (p[i] == 0) s = i;
	}

	auto ans = dfs(s, 0);

	if (!good) {
		cout << "NO\n";
		return 0;
	}

	vector<int> v(n + 1);
	int mn = 0;
	for (auto [x, y] : ans) {
		v[y] = x;
		mn = min(mn, x);
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << v[i] - mn + 1 << " ";

	return 0;
}