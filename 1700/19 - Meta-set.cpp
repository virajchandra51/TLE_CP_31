#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(k(n^2 log n))
// Memory Complexity: O(kn)

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<vector<int>> cards(n, vector<int>(k));
	map<vector<int>, int> mp;
	for(auto &c : cards) {
		for(auto &x : c) cin >> x;
		mp[c] = 0;
	}

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			vector<int> comp(k);
			for(int l = 0; l < k; l++) {
				if(cards[i][l] == cards[j][l])
					comp[l] = cards[i][l];
				else
					comp[l] = 3 - (cards[i][l] + cards[j][l]);
			}
			if(mp.count(comp)) mp[comp]++;
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (mp[cards[i]] * (mp[cards[i]]-1))/2;
	}
	cout << ans;

	return 0;
}