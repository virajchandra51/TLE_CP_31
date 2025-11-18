#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(nk)
// Memory Complexity: O(nk)

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		int dp[n][k][2];

		for(int i = 0; i < n; i++) dp[i][0][0] = dp[i][0][1] = 1;

		for(int j = 1; j < k; j++) {
			for(int i = n-1; i >= 0; i--) {
				int v1 = 1, v2 = 1;
				if(i-1 >= 0) v1 = dp[i-1][j-1][0];
				if(i+1 < n) v2 = dp[i+1][j][1];
				dp[i][j][1] = (v1+v2)%mod;
			}
			for(int i = 0; i < n; i++) {
				int v1 = 1, v2 = 1;
				if(i-1 >= 0) v1 = dp[i-1][j][0];
				if(i+1 < n) v2 = dp[i+1][j-1][1];
				dp[i][j][0] = (v1+v2)%mod;
			}
		}

		cout << dp[0][k-1][1] << "\n";
	}	

	return 0;
}