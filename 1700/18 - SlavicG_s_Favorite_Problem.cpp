#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(N log N)
// Memory Complexity: O(N)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, a, b; cin >> n >> a >> b; a--; b--;
		vector<vector<pair<int, int>>> adj(n);
		for(int i = 0; i < n-1; i++) {
			int x, y, w; cin >> x >> y >> w; x--; y--;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
		}

		auto dfs = [&](auto&& self, int x, int p, int xr, vector<int> &v, int stop = -1) -> void {
			if(x == stop) return;
			v[x] = xr;
			for(auto &[y, w] : adj[x]) {
				if(y == p) continue;
				self(self, y, x, (xr ^ w), v, stop);
			}
		};

		vector<int> v1(n, -1), v2(n, -1);
		dfs(dfs, a, -1, 0, v1, b);
		dfs(dfs, b, -1, 0, v2);

		bool ans = (v1[b] == 0);
		set<int> s;
		for(int i = 0; i < n; i++) {
			if(i == b || v2[i] == -1) continue;
			s.insert(v2[i]);
		}
		for(int i = 0; i < n; i++) {
			if(v1[i] != -1 && s.count(v1[i])) ans = true;
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}