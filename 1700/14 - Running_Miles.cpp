#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Memory Complexity: O(n)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<int> a(n); for(auto &x : a) cin >> x;
		
		vector<int> pref(n);
		for(int i = 0; i < n; i++) {
			pref[i] = a[i] + i;
			if(i) pref[i] = max(pref[i], pref[i-1]);
		}

		vector<int> suf(n);
		for(int i = n-1; i >= 0; i--) {
			suf[i] = a[i] - i;
			if(i < n-1) suf[i] = max(suf[i], suf[i+1]);
		}

		int ans = 0;
		for(int i = 1; i < n-1; i++) {
			ans = max(ans, pref[i-1]+a[i]+suf[i+1]);
		}
		cout << ans << "\n";
	}

	return 0;
}