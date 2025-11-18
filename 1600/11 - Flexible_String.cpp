#include <bits/stdc++.h>
using namespace std;

// Flexible String
// Time Complexity: O(2^10 * n)
// Memory Complexity: O(n)

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		string a, b; cin >> a >> b;

		vector<int> id(26, -1);
		vector<char> u;
		for(char c : a) {
			if(id[c-'a'] == -1) {
				id[c-'a'] = u.size();
				u.push_back(c);
			}
		}

		ll ans = 0;
		int uc = u.size(), bc = min(k, uc);
		for(int bm = 0; bm < (1<<uc); bm++) {
			if(__builtin_popcount(bm) != bc) continue;

			ll cnt = 0, match = 0;
			for(int i = 0; i < n; i++) {
				if(a[i] == b[i] || (bm & (1<<id[a[i]-'a']))) match++;
				else {
					cnt += match*(match+1)/2;
					match = 0;
				}
			}
			cnt += match*(match+1)/2;
			ans = max(ans, cnt);
		}

		cout << ans << "\n";
	}

	return 0;
}