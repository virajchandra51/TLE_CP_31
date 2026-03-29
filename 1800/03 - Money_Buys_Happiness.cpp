#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e15;

int n, maxH;
ll x;
vector<ll> c, h;
vector<vector<ll>> dp;

ll solve(int i, int H) {
    // returns dp[i][H] = max money saved after months 0..i when targeting H happiness
    if (i < 0) return (H == 0) ? 0 : -inf;

    if (dp[i][H] != -1) return dp[i][H]; // already computed

    // Option 1: not take month i
    ll money1 = solve(i - 1, H) + x;

    // Option 2: take month i
    ll money2 = -inf;
    if (H >= h[i]) {
        ll prev_buy = solve(i - 1, H - h[i]);
        if (prev_buy >= c[i]) {
            money2 = max(money2, prev_buy - c[i] + x);
        }
    }
    return dp[i][H] = max(money1, money2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        c.assign(n, 0);
        h.assign(n, 0);
        for (int i = 0; i < n; ++i) cin >> c[i] >> h[i];

        maxH = accumulate(h.begin(), h.end(), 0LL);
        dp.assign(n, vector<ll>(maxH + 1, -1));

        // check from largest happiness downward for the first feasible H
        for (int H = maxH; H >= 0; --H) {
            ll saved = solve(n - 1, H); // dp[n-1][H]
            if (saved >= 0) { cout << H << '\n'; break; }
        }
    }
    return 0;
}