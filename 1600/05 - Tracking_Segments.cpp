#include <bits/stdc++.h>
using namespace std;

// Tracking Segments
// Time Complexity: O( (N + M + Q) log Q )
// Space Complexity: O( N + M + Q )

int n, m, q;
vector<pair<int, int>> seg;
vector<int> qry;

bool check(int x) { // check if first x queries satisfy any segement
	vector<int> a(n, 0);
	for(int i = 0; i < x; i++) {
		a[qry[i]] = 1;
	}
	for(int i = 1; i < n; i++) a[i] += a[i-1];

	for(auto &[l ,r] : seg) {
		int sum = a[r] - ((l > 0) ? a[l-1] : 0);
		if(sum > (r - l + 1)/2) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		cin >> n >> m;
		seg.resize(m);
		for(auto &[l, r] : seg) {
			cin >> l >> r; l--; r--;
		}

		cin >> q;
		qry.resize(q);
		for(auto &x : qry) {
			cin >> x; x--;
		}

		int l = 1, r = q, ans = INT_MAX;
		while(l <= r) {
			int mid = (l + r)/2;
			if(check(mid)) {
				ans = min(ans, mid);
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		cout << (ans == INT_MAX ? -1 : ans) << "\n";
	}

	return 0;
}