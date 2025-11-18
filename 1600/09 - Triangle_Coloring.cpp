#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Memory Complexity: O(1)

using ll = long long;

const ll MOD = 998244353;
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

	int n; cin >> n;

	ll ans = 1;
	for(int i = 1, j = n/3; i <= n/6; i++, j--) {
		ans = mul(ans, j);
		ans = mul(ans, inv(i));
	}

	vector<int> v(3);
	for(int i = 0; i < n; i++) {
		cin >> v[i % 3];
		if(i % 3 == 2) {
			sort(v.begin(), v.end());
			int m = 1;
			if(v[0] == v[1]) m++;
			if(v[0] == v[2]) m++;
			ans = mul(ans, m);
		}
	}

	cout << ans;

	return 0;
}