#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Memory Complexity: O(n)

using ll = long long;
const ll MOD = 1000000007;
ll add(ll a, ll b, ll m = MOD) { return ((a%m) + (b%m) + m) % m; }
ll sub(ll a, ll b, ll m = MOD) { return ((a%m) - (b%m) + m) % m; }
ll mul(ll a, ll b, ll m = MOD) { return ((a%m) * (b%m)) % m; }
ll modexp(ll a, ll e, ll m = MOD) {
    a %= m; ll r = 1;
    while (e) {
        if (e & 1) r = mul(r, a, m);
        a = mul(a, a, m);
        e >>= 1;
    }
    return r;
}
ll inv(ll a, ll m = MOD) { return modexp(a, m - 2, m); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for(auto &x : a) cin >> x;
		sort(a.rbegin(), a.rend());

		// element needed to be counted for nCr == a[k-1]
		int N = 0, R = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] == a[k-1]) {
				N++;
				if(i < k) R++;
			}
		}

		// now just need nCr value = n!/(n-r)!r!
		ll val = 1;
		for(int i = 1; i <= R; i++) {
			val = mul(val, N-i+1);
			val = mul(val, inv(i));
		}
		cout << val << "\n";
	}

	return 0;
}