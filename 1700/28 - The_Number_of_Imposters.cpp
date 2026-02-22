#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity : O(n+m)
// Memory Complexity : O(n+m)

int n, m;
vector<vector<int>> adj;
vector<int> col;
int pos, c1, c2, ans;

void dfs(int x) {
	if(x < n) {
		if(col[x] == 1) c1++;
		else c2++;
	}
	int next_col = ((col[x] == 1) ? 2 : 1);
	for(auto &y : adj[x]) {
		if(col[y]) {
			if(col[y] != next_col) pos = 0;
			continue;
		}
		col[y] = next_col;
		dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		cin >> n >> m;
		adj = vector<vector<int>>(n+m);
		for(int j = 0, fake = n; j < m; j++) {
			int u, v; cin >> u >> v; u--; v--; 
			string c; cin >> c;
			if(c == "imposter") {
				adj[u].push_back(v); adj[v].push_back(u);
			}
			else {
				adj[u].push_back(fake); adj[fake].push_back(u);
				adj[v].push_back(fake); adj[fake].push_back(v);
				fake++;
			}
		}

		col = vector<int>(n+m, 0);
		ans = 0; pos = 1;
		for(int i = 0; i < n; i++) {
			if(col[i]) continue;
			c1 = c2 = 0;
			col[i] = 1; dfs(i);
			ans += max(c1, c2);
		}

		if(!pos) ans = -1;
		cout << ans << "\n";
	}

	return 0;
}