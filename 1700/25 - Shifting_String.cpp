#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(T * n^2)
// Memory Complexity: O(n)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		string s; cin >> s;
		vector<int> v(n);
		for(auto &x : v) { cin >> x; x--; }

		vector<bool> vis(n, false);
		ll L = 1; 
		for(int i = 0; i < n; i++) {
			if(vis[i]) continue;

			string temp1;
			for(int cur = i; !vis[cur]; cur = v[cur]) {
				temp1.push_back(s[cur]); vis[cur] = true;
			}
			string temp2(temp1);
			int cnt = 0;
			do {
				temp2 = temp2.substr(1, int(temp2.size())-1) + temp2.substr(0, 1);
				cnt++;
			} while(temp1 != temp2);
			L = lcm(L, cnt);
		}
		cout << L << "\n";
	}

	return 0;
}