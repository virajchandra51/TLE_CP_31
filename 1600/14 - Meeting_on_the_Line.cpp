#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N log((X + T)* precision^-1)
//                       aka. O (N log_2(2 * 10^8 * 10^6))
//                             = O(N * 50) approx
// Memory Complexity: O(N)

using ld = long double;

int n;
vector<int> x, t;
ld best;

bool check(ld T) { // given a time T, is there some point all can meet?
	ld L = 0, R = 1e8; // total interval
	for(int i = 0; i < n; i++) {
		// interval that this ith person can travel in given time
		ld l = (ld)x[i] - max(T - t[i], (ld)0);
		ld r = (ld)x[i] + max(T - t[i], (ld)0);

		// lower the total interval
		L = max(L, l); R = min(R, r);

		if(R < L) return false; // interval of valid meeting point is empty
	}
	best = (L+R)/2;
	return true; // interval of valid meeting point is not empty
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		cin >> n;
		x.resize(n); for(auto &xi : x) cin >> xi;
		t.resize(n); for(auto &ti : t) cin >> ti;

		// if everyone can meet at time T, then they can meet at time T' > T
		// therefore T is monotonic
		ld l = 0, r = 1e9;
		for(int i = 0; i <= 50; i++) {
			ld mid = (l + r)/2;
			if(check(mid)) {
				r = mid;
			}
			else {
				l = mid;
			}
		}

		cout << setprecision(16) << best << "\n";
	}

	return 0;
}