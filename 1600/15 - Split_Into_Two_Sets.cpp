#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Memory Complexity: O(n)

void dfs(int x, vector<vector<int>> &adj, vector<int> &color, bool &pos) {
	for(auto y : adj[x]) {
		if(color[y] != -1) {
			if(color[y] == color[x]) {
				// not bip
				pos = false;
				return;
			}
			continue;
		}

		color[y] = 1 - color[x];
		dfs(y, adj, color, pos);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<vector<int>> doms_for_num(n);
		vector<pair<int, int>> domino(n);
		for(int i = 0; i < n; i++) {
			cin >> domino[i].first >> domino[i].second;
			doms_for_num[domino[i].first-1].push_back(i);
			doms_for_num[domino[i].second-1].push_back(i);
		}
		// now if doms for num > 2 for anything not possible
		bool pos = true;
		vector<vector<int>> adj(n);
		for(int i = 0; i < n; i++) {
			if(doms_for_num[i].size() > 2) {
				pos = false; break;
			}
			if(doms_for_num[i].size() == 2) {
				adj[doms_for_num[i][0]].push_back(doms_for_num[i][1]);
				adj[doms_for_num[i][1]].push_back(doms_for_num[i][0]);
			}
		}
		if(!pos) {
			cout << "NO\n"; continue;
		}

		vector<int> color(n, -1);
		for(int i = 0; i < n; i++) {
			if(color[i] != -1) continue;
			color[i] = 0;
			dfs(i, adj, color, pos);
		}

		if(pos) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}