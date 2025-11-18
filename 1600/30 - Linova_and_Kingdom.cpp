#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Memory Complexity: O(n)

int n, k;
vector<vector<int>> adj;
vector<int> d, s, v;

void dfs(int x, int p) {
	for(auto &y : adj[x]) {
		if(y == p) continue;
		d[y] = d[x] + 1;
		dfs(y, x);
		s[x] += s[y] + 1;
	}
	v[x] = d[x] - s[x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	adj.resize(n);
	for(int i = 0; i < n-1; i++) {
		int x, y; cin >> x >> y; x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	d.resize(n); s.resize(n); v.resize(n); d[0] = 0;
	dfs(0, -1);

	sort(v.rbegin(), v.rend());
	cout << accumulate(v.begin(), v.begin()+k, 0ll) << "\n";

	return 0;
}