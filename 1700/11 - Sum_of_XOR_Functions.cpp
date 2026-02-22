#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
void add(ll &a, ll x) { a += x; a %= MOD; }

// Time Complexity : O(n log(ai))
// Memory Complexity : O(n)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for(auto &x : a) cin >> x;

	ll ans = 0;
	for(int j = 0; j < 31; j++) {
		ll sum = 0;
		ll on = 0, off = 0, onc = 0, offc = 0;
		for(int i = 0; i < n; i++) {
			add(on, onc); add(off, offc);
			if((a[i] & (1 << j))) {
				swap(on, off); swap(onc, offc);
				on++; onc++;
			}
			else {
				off++; offc++;
			}
			add(sum, on);
		}
		add(ans, sum << j);
	}

	cout << ans << "\n";


	return 0;
}