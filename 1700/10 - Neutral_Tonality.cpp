#include <bits/stdc++.h>
using namespace std;

// Time Complexity :   O(n + m)
// Memory Complexity : O(n + m)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, m; cin >> n >> m;
		vector<int> a(n), b(m);
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;
		sort(b.rbegin(), b.rend());
		vector<int> c;
		for(int i = 0, j = 0; (i < n || j < m);) {
			if(i == n) { c.push_back(b[j++]); continue; }
			if(j == m) { c.push_back(a[i++]); continue; }
			if(b[j] >= a[i]) c.push_back(b[j++]);
			else c.push_back(a[i++]);
		}
		for(auto &x : c) cout << x << " ";
		cout << "\n";
	}

	return 0;
}