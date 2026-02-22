#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n log n)
// Memory Complexity : O(n)

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
		int n, m; cin >> n >> m;
		map<int, int> mp;
		for(int i = 0; i < n; i++) {
			int x; cin >> x; mp[x]++;
		}

		vector<int> v, pref;
		int prod = 1;
		for(auto &[x, y] : mp) {
			v.push_back(x);
			prod = mul(prod, y);
			pref.push_back(prod);
		}

		int ans = 0;
		for(int i = 0; i <= int(v.size()) - m; i++) {
			if(v[i+m-1] - v[i] >= m) continue;
			int val = pref[i+m-1];
			if(i) val = mul(val, inv(pref[i-1]));
			ans = add(ans, val);
		}
		cout << ans << "\n";
	}

	return 0;
}