#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity : O(n log n)
// Memory Complexity : O(n)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		map<int, int> m1, m2;
		vector<pair<int, int>> v(n);
		for(auto &[x, y] : v) {
			cin >> x >> y;
			m1[x]++; m2[y]++;
		}
		ll ans = ((ll)n*(n-1)*(n-2))/6;
		for(auto &[x, y] : v) {
			ans -= ((ll)m1[x]-1)*(m2[y]-1);
		}
		cout << ans << "\n";
	}

	return 0;
}