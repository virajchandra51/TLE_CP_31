#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * max(ai))
// Memory Complexity: O(n * max(ai))

using ll = long long;
const ll MOD = 1e9 + 7;
void add(ll &a, ll x) { a += (x + MOD); a %= MOD; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for(auto &x : a) cin >> x;

		vector<vector<ll>> dp(n, vector<ll>(64, 0));
		for(int i = 0; i < n; i++) {
			if(i) for(int j = 0; j < 64; j++) {
				add(dp[i][j], dp[i-1][j]);
				add(dp[i][(j&a[i])], dp[i-1][j]);
			}
			add(dp[i][a[i]], 1);
		}

		ll ans = 0;
		for(int j = 0; j < 64; j++) {
			if(__builtin_popcount(j) != k) continue;
			add(ans, dp[n-1][j]);
		}
		cout << ans << "\n";
	}

	return 0;
}