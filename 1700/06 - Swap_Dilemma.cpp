#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Memory Complexity : O(n)

int perm_parity(vector<int> p){
	int n = p.size(), ans = 0;
	for(int i = 0; i < n; i++){
		while(p[i] != i+1){
			swap(p[i], p[p[i]-1]);
			ans ^= 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<int> b(n);

		unordered_map<int, int> mp;
		for(int i = 0; i < n; i++) {
			int x; cin >> x; mp[x] = i+1;
		}

		bool pos = true;
		for(auto &x : b) {
			cin >> x;
			if(mp.count(x)) x = mp[x];
			else pos = false;
		}

		if(pos && perm_parity(b) % 2 == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}