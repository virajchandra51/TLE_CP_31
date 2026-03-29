#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
	}
	
	int ind = 1, ans = n;
	vector<int> comp(n, 0);
	for (int i = 0; i < n; i++) {
		if (comp[i]) continue;
		int v = i;
		while (comp[v] == 0) {
			comp[v] = ind;
			v = p[v];
                }
		ind++; ans--;
	}
	
	for (int i = 0; i < n - 1; i++) {
		if (comp[i] == comp[i + 1]) {
			cout << ans - 1 << endl;
			return;
		}
	}
	cout << ans + 1 << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();
}

// Time Complexity - O(n)
// Space Complexity - O(n)