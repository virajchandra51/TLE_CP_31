#include <bits/stdc++.h>
using namespace std;

// Drunken Maze
// Time Complexity: O(n * m)
// Memory Complexity: O(n * m)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	int si, sj, ei, ej;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char c; cin >> c;
			if(c == '#') mat[i][j] = 0;
			else mat[i][j] = 1;
			if(c == 'S') si = i, sj = j;
			if(c == 'T') ei = i, ej = j;
		}
	}

	struct state { int i, j, val; };
	auto adj = [&](int i, int j, int val) {
		vector<state> ans;
		if(i+1 < n && mat[i+1][j] && val != 3) ans.push_back({i+1, j, (val/4 == 0) ? val+1 : 1});
		if(i-1 >= 0 && mat[i-1][j] && val != 7) ans.push_back({i-1, j, (val/4 == 1) ? val+1 : 5});
		if(j+1 < m && mat[i][j+1] && val != 11) ans.push_back({i, j+1, (val/4 == 2) ? val+1 : 9});
		if(j-1 >= 0 && mat[i][j-1] && val != 15) ans.push_back({i, j-1, (val/4 == 3) ? val+1 : 13});
		return ans;
	};

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(16, INT_MAX)));
	int ans = INT_MAX;
	queue<state> q; q.push({si, sj, 0}); dp[si][sj][0] = 0;
	while(!q.empty()) {
		state x = q.front(); q.pop();
		for(auto &y : adj(x.i, x.j, x.val)) {
			if(dp[y.i][y.j][y.val] != INT_MAX) continue;
			dp[y.i][y.j][y.val] = dp[x.i][x.j][x.val]+1;
			q.push(y);
		}

		if(x.i == ei && x.j == ej) ans = min(ans, dp[x.i][x.j][x.val]);
	}

	cout << (ans == INT_MAX ? -1 : ans);

	return 0;
}