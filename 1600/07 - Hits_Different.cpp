#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(N_max + T)
// Memory Complexity: O(N_max)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int RC = 2023, N_max = RC*(RC+1)/2;
	vector<ll> dp1(N_max, 0), dp2(N_max, 0); // dp1 -> sum of diagonal at that point
	// dp2 -> ans at the point
	dp1[0] = dp2[0] = 1;

	ll idx = 1; // current index (0-indexed)
	for(int rc = 1; rc < RC; rc++) { // row (0-indexed)
		int prev_row = idx - rc;
		for(int i = 0; i <= rc; i++) {
			dp1[idx] = (idx+1)*(idx+1) + ((i > 0) ? dp1[prev_row+i-1] : 0);
			dp2[idx] = dp1[idx] + ((i < rc) ? dp2[prev_row+i] : 0);
			idx++;
		}
	}

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n; n--;
		cout << dp2[n] << "\n";
	}

	return 0;
}