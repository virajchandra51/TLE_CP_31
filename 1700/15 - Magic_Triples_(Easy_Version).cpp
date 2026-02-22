#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(N sqrt(max(Ai)))
// Memory Complexity : O(max(Ai) + N)

using ll = long long;

int cnt[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) { cin >> a[i]; cnt[a[i]]++; }

		ll ans = 0;
		for(int i = 0; i < n; i++) {
			ans += ll(cnt[a[i]]-1)*(cnt[a[i]]-2);
			for(int b = 2; (ll)a[i]*b*b <= 1000000ll; b++) {
				ans += ll(cnt[a[i]*b])*cnt[a[i]*b*b];
			}
		}

		for(int i = 0; i < n; i++) cnt[a[i]]--;

		cout << ans << "\n";
	}

	return 0;
}