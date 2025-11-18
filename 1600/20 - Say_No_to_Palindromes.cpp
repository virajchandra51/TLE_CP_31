#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + q)
// Memory Complexity: O(n)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<string> tiles = {"abc", "acb", "bac", "bca", "cab", "cba"};

	int tc = 1; // cin >> tc;
	while(tc--) {
		int n, q; cin >> n >> q;
		string s; cin >> s;
		
		vector<vector<int>> pref(6, vector<int>(n, 0));
		for(int j = 0; j < 6; j++) {
			for(int i = 0; i < n; i++) {
				if(i) pref[j][i] += pref[j][i-1];
				if(s[i] != tiles[j][i%3]) pref[j][i]++;
			}
		}

		while(q--) {
			int l, r; cin >> l >> r; l--; r--;
			int ans = (r-l+1);
			for(int j = 0; j < 6; j++) {
				int val = pref[j][r];
				if(l-1 >= 0) val -= pref[j][l-1];
				ans = min(ans, val);
			}
			cout << ans << "\n";
		}
	}

	return 0;
}