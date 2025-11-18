#include <bits/stdc++.h>
using namespace std;

// TC: O(B_max^2 + N^2)
// MC: O(B_max + N)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int b_max = 1e3;
	vector<int> dp(b_max+1, INT_MAX);
	dp[1] = 0;
	for(int i = 1; i <= b_max; i++) {
		for(int x = 1; x <= i; x++) {
			int val = i + (i/x);
			if(val <= b_max) dp[val] = min(dp[val], dp[i] + 1);
		}
	}

	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		vector<int> b(n);
		for(auto &x : b) {
			cin >> x; x = dp[x];
		}
		vector<int> c(n);
		for(auto &x : c) cin >> x;

		vector<int> kdp(12*n + 1, 0);
		for(int j = 0; j < n; j++) {
			for(int i = 12*n; i >= b[j]; i--) {
				kdp[i] = max(kdp[i], kdp[i-b[j]]+c[j]);
			}
		}

		cout << kdp[min(k, 12*n)] << "\n";
	}

	return 0;
}