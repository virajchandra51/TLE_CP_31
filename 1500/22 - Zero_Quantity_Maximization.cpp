#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i; // n
    for (auto &i : b)
        cin >> i; // n

    map<pair<int, int>, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0)
                ans++;
            continue;
        }

        int p = -b[i], q = a[i];
        int g = __gcd(abs(p), abs(q)); // log(1e9)
        p /= g;
        q /= g;
        if (q < 0) {
            p *= -1;
            q *= -1;
        }
        mp[{p, q}]++; // logn
    } // n*log(1e9)

    int mx = 0;
    for (auto it : mp) {
        mx = max(mx, it.second);
    } // n
    ans += mx;

    cout << ans << '\n';

    return 0;
}

// tc : O(n*log(max(a[i], b[i]))) -> 2e5*30 -> 6e6
// sc : O(n)