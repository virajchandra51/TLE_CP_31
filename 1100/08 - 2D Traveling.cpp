#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<ll> x(n + 1), y(n + 1);//N
    for (int i = 1; i <= n; i++) {//N
        cin >> x[i] >> y[i];
    }
    ll ans = abs(x[s] - x[t]) + abs(y[s] - y[t]);
    ll mins = 1e17 , mint = 1e17;
    for (int i = 1; i <= k; i++) {//K
        mins = min(mins, abs(x[s] - x[i]) + abs(y[s] - y[i]));
        mint = min(mint, abs(x[t] - x[i]) + abs(y[t] - y[i]));
    }
    ans = min(ans, mins + mint);
    cout << ans << endl;
    // T.C :- O(n)
    // S.C :- O(n)
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}