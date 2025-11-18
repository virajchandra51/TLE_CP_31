#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity : O(log n)
// Memory Complexity : O(1)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		ll n, x; cin >> n >> x;
		if(n == x) {
			cout << n << "\n"; continue;
		}

		ll ans = -1;
		for(int i = 0; i <= 61; i++) {
			if(((n>>i)<<i) == x) {
				ll val = ((n>>i)<<i) | (1ll<<i);
				if(val >= n) ans = val;
				else ans = -1;
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}