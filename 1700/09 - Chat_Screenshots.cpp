#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n k)
// Mem Complexity:  O(n k)

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		vector<vector<int>> out(n);
		vector<int> in(n, 0);
		for(int i = 0; i < k; i++) {
			vector<int> v(n);
			for(int i = 0; i < n; i++) {
				cin >> v[i]; if(i <= 1) continue;
				in[v[i]-1]++;
				out[v[i-1]-1].push_back(v[i]-1);
			}
		}
		vector<int> top;
		for(int i = 0; i < n; i++) {
			if(in[i]) continue;
			queue<int> q; q.push(i);
			while(!q.empty()) {
				auto x = q.front(); q.pop(); top.push_back(x); in[x] = -1;
				for(auto &y : out[x]) {
					in[y]--;
					if(in[y] == 0) q.push(y);
				}
			}
		}
		if((int)top.size() != n) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}