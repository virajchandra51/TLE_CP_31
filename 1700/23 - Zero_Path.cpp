#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(nm)
// Memory Complexity: O(nm)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, m; cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for(auto &aa : a) for(auto &x : aa) cin >> x;

		vector<vector<int>> dp1 = a, dp2 = a;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(!i && !j) continue;
				dp1[i][j] = a[i][j] + min(((i > 0) ? dp1[i-1][j] : INT_MAX), ((j > 0) ? dp1[i][j-1] : INT_MAX));
				dp2[i][j] = a[i][j] + max(((i > 0) ? dp2[i-1][j] : INT_MIN), ((j > 0) ? dp2[i][j-1] : INT_MIN));
			}
		}

		if(dp1[n-1][m-1] <= 0 && dp2[n-1][m-1] >= 0 && dp2[n-1][m-1] % 2 == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}