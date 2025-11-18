#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Memory Complexity: O(n)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<int> dp(n+1, false); dp[0] = true;
		for(int i = 1; i <= n; i++) {
			int x; cin >> x;
			if(dp[i-1] && i+x <= n) dp[i+x] = true;
			if(i-x-1 >= 0) dp[i] = (dp[i] || dp[i-x-1]);
		}
		if(dp[n]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}