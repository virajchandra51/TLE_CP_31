#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(k)
// Memory Complexity: O(k)

using ll = long long;
const ll MOD = 1000000007;
ll add(ll a, ll b, ll m = MOD) { return ((a%m) + (b%m) + m) % m; }
ll mul(ll a, ll b, ll m = MOD) { return ((a%m) * (b%m)) % m; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	const int NMAX = 2 * 1e5 + 1;
	vector<int> pow2(NMAX); pow2[0] = 1;
	for(int i = 1; i <= NMAX; i++) pow2[i] = mul(2, pow2[i-1]);

	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;

		vector<vector<int>> dp(k+1, vector<int>(2, 0));
		dp[0][1] = 1;

		for(int i = 1; i <= k; i++) {
			dp[i][0] = mul(pow2[n], dp[i-1][0]); // prev already greater
			if(n % 2 == 0) dp[i][0] = add(dp[i][0], dp[i-1][1]); // prev equal, became greater now AND = 1, XOR = 0 (n % 2 == 0)
			dp[i][1] = mul(pow2[n-1] - (n % 2 == 0), dp[i-1][1]); // prev equal, AND = XOR = 0 currently (even no. bits are 1s)
			if(n % 2 == 1) dp[i][1] = add(dp[i][1], dp[i-1][1]); // prev equal and AND = XOR = 1 (n % 2 == 1)
		}

		cout << add(dp[k][0], dp[k][1]) << "\n";
	}

	return 0;
}