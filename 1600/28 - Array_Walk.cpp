#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * z)
// Memory Complexity: O(n)

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, k, Z; cin >> n >> k >> Z;
		vector<int> a(n); for(auto &x : a) cin >> x;
		
		ll ans = 0;
		for(int z = 0; z <= Z && 2*z <= k; z++) {
			ll res = accumulate(a.begin(), a.begin()+k-2*z+1, 0ll); 

			int mx = 0;
			for(int i = 1; i <= min(k - 2*z + 1, n-1); i++) {
				mx = max(a[i] + a[i-1], mx);
			}
			res += z*mx;
			ans = max(ans, res);
		}

		cout << ans << "\n";
	}

	return 0;
}