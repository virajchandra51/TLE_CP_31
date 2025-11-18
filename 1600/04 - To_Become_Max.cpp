#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(n log n)
// Memory Complexity : O(n)

int n, k;
vector<int> a;

bool check(int x) {
	for(int i = 0; i < n; i++) {
		ll cost = 0; // number of operations
		for(int j = i, y = x; j < n; j++, y--) {
			if(y <= a[j]) break;
			if(j == n-1) cost += (int)1e9;
			else cost += (y - a[j]);
		}
		if(cost <= k) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		cin >> n >> k;
		a.resize(n);
		for(auto &x : a) cin >> x;

		int l = *max_element(a.begin(), a.end()), r = l + n, ans = l;
		while(l <= r) {
			int mid = (l+r)/2;
			if(check(mid)) {
				ans = max(ans, mid);
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}