#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll l, r;
    cin >> l >> r;
    vector<ll>ans;//n
    for (int i = 1; i <= n; i++) {//n
        ll temp = ((l + i - 1) / i) * i;
        ans.push_back(temp);
        if (temp > r) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto it : ans) {//n
        cout << it << " ";
    }
    cout << endl;
    // T.C :- O(n)
    // S.C :- O(n)
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}