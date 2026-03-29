#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
bool reachable(unsigned long long X, unsigned long long Y) {
    if (Y < X) {
        return false;
    }
    if (__builtin_popcountll(Y) > __builtin_popcountll(X)) {
        return false;
    }
    while (Y != 0) {
        int lsbIndexY = __builtin_ctzll(Y);
        int lsbIndexX = __builtin_ctzll(X);

        if (lsbIndexY < lsbIndexX) {
            return false;
        }
        Y = Y & (Y - 1);
        X = X & (X - 1);
    }
    return true;
}
void solve()
{
    ll u, v;
    cin >> u >> v;
    bool flag = reachable(u, v);
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
// Time Complexity: O(log(max(u, v))) per test case
// Space Complexity: O(1)