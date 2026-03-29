#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXA = 1000000; // values ai in [1,1e6]
    // prepare random masks once
    vector<ull> mask(MAXA + 1);
    std::mt19937_64 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 1; i <= MAXA; ++i) mask[i] = rng();

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        // build prefix-xor of masks
        vector<ull> pref(n+1, 0);
        for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] ^ mask[a[i]];

        while (q--) {
            int l, r;
            cin >> l >> r;
            ull x = pref[r] ^ pref[l-1];
            cout << (x == 0 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
// TC : O(n + q)
// SC : O(maxA + n)