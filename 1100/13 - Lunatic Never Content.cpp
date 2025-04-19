#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;//n
    int ans = 0;
    for (int i = 0; i < n; ++i) {//nlog(maxai)
        ans = __gcd(ans, abs(a[i] - a[n - i - 1]));
    }
    cout << ans << endl;
    // T.C :- O(n*log(1e9))
    // S,C :- O(n)
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}