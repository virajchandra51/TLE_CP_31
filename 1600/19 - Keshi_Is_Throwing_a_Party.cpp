#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Memory Complexity: O(n)

int n;
vector<pair<int, int>> v;

bool check(int x) {
	int c = 0;
	for(int i = 0; i < n; i++) {
		if(v[i].second >= c && x-c-1 <= v[i].first) c++;
	}
	return c >= x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		cin >> n;
		v.resize(n);
		for(auto &[x, y] : v) cin >> x >> y;

		int l = 1, r = n, best = 1;
		while(l <= r) {
			int mid = (l + r)/2;

			if(check(mid)) {
				best = max(mid, best);
				l = mid + 1;
			}
			else r = mid - 1;
		}

		cout << best << "\n";
	}

	return 0;
}