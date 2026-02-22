#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(n^2 * k)
// Memory Complexity: O(n * k)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, l, k; cin >> n >> l >> k;
	vector<int> d(n), a(n);
	for(auto &x : d) cin >> x;
	for(auto &x : a) cin >> x;
	d.push_back(l);

	vector<vector<ll>> dp(n+1, vector<ll>(k+1, LLONG_MAX / 10));
	for(int j = 0; j <= k; j++) dp[n][j] = 0;

	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j <= k; j++) {
			// j == allowed removals
			for(int nxt = i+1; nxt <= min(i+1+j, n); nxt++) {
				dp[i][j] = min(dp[i][j], a[i]*(d[nxt]-d[i]) + dp[nxt][j - (nxt-i-1)]);
			}
		}
	}

	cout << dp[0][k];

	return 0;
}