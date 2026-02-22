#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Memory Complexity: O(n)

int dfs(int x, int p, int dep, vector<vector<int>> &adj, vector<vector<int>> &d) {
	int mx_dep = dep;
	for(auto &y : adj[x]) {
		if(y == p) continue;
		mx_dep = max(mx_dep, dfs(y, x, dep+1, adj, d));
	}
	d[dep].push_back(mx_dep);
	return mx_dep;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		for(int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<vector<int>> d(n);
		dfs(0, -1, 0, adj, d);

		int ans = n;
		multiset<int> s;
		for(int i = 0; i < n; i++) {
			for(auto &x : d[i]) s.insert(x);
			while(!s.empty() && (*s.begin()) < i) s.erase(s.begin());
			ans = min(ans, n - (int)s.size());
		}
		cout << ans << "\n";
	}

	return 0;
}