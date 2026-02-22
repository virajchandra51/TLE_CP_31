#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n m^2 log(n m^2))
// Memory Complexity: O(n m^2)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, m; cin >> n >> m;
		vector<vector<int>> v(n, vector<int>(m));
		for(auto &vv : v) for(auto &x : vv) cin >> x;
		
		set<vector<int>> s;
		for(int i = 0; i < n; i++) {
			vector<int> inv(m);
			for(int j = 0; j < m; j++) {
				inv[v[i][j]-1] = j+1;
			}
			vector<int> pref;
			for(int j = 0; j < m; j++) {
				pref.push_back(inv[j]);
				s.insert(pref);
			}
		}

		for(int i = 0; i < n; i++) {
			int ans = 0;
			vector<int> pref;
			for(int j = 0; j < m; j++) {
				pref.push_back(v[i][j]);
				if(!s.count(pref)) break;
				ans++;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}

	return 0;
}