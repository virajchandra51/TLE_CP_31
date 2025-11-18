#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(nk)
// Memory Complexity: O(n + k)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k; cin >> n >> k;
	string s; cin >> s;
	string ans(k, 'z');

	for(int len = 1; len <= n; len++) {
		string t = s.substr(0, len);
		while((int)t.size() < k) t = t + t;
		t = t.substr(0, k);
		ans = min(ans, t);
	}

	cout << ans << "\n";

	return 0;
}