#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + q)
// Memory Complexity: O(n)

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(auto &x : a) cin >> x;

	ll ans = ((ll)n*(n+1))/2;
	for(int i = 1; i < n; i++) {
		if(a[i] != a[i-1]) {
			ans += ll(i)*(n - i);
		}
	}

	while(m--) {
		int i, x; cin >> i >> x; i--;
		if(i && a[i] != a[i-1]) ans -= ll(i)*(n - i);
		if(i+1 < n && a[i+1] != a[i]) ans -= ll(i+1)*(n - (i+1));
		a[i] = x;
		if(i && a[i] != a[i-1]) ans += ll(i)*(n - i);
		if(i+1 < n && a[i+1] != a[i]) ans += ll(i+1)*(n - (i+1));
		cout << ans << "\n";
	}

	return 0;
}