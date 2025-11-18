#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(n)
// Memory Complexity: O(n)

void dfs(int x, int p, vector<pair<int, int>> &v, vector<vector<int>> &adj, vector<vector<ll>> &dp) {
	for(auto &y : adj[x]) {
		if(y == p) continue;
		dfs(y, x, v, adj, dp);
		dp[x][0] += max(dp[y][0]+abs(v[x].first-v[y].first), dp[y][1]+abs(v[x].first-v[y].second));
		dp[x][1] += max(dp[y][0]+abs(v[x].second-v[y].first), dp[y][1]+abs(v[x].second-v[y].second));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<pair<int, int>> v(n);
		for(auto &[x, y] : v) cin >> x >> y;
		vector<vector<int>> adj(n);
		for(int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<vector<ll>> dp(n, vector<ll>(2, 0));

		dfs(0, -1, v, adj, dp);

		cout << max(dp[0][0], dp[0][1]) << "\n";
	}

	return 0;
}