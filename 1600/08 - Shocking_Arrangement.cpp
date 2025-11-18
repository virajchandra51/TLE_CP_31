#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Memory Complexity: O(n)

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<int> v(n);

		bool nz = false;
		for(auto &x : v) {
			cin >> x;
			if(x) nz = true;
		}

		if(!nz) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";

		vector<int> pos, neg;
		for(auto &x : v) {
			if(x >= 0) pos.push_back(x);
			else neg.push_back(x);
		}

		vector<int> ans(n);
		ll psum = 0;
		for(int i = 0; i < n; i++) {
			if(psum <= 0 && !pos.empty()) {
				ans[i] = pos.back(); pos.pop_back();
			}
			else {
				ans[i] = neg.back(); neg.pop_back();
			}
			psum += ans[i];
		}

		for(auto &x : ans) cout << x << " ";
		cout << "\n";
	}

	return 0;
}