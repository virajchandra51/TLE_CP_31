#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<ll> fa, fb;

    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            fa.push_back(i);
            if (i * i != a) fa.push_back(a / i);
        }
    }

    for (ll i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            fb.push_back(i);
            if (i * i != b) fb.push_back(b / i);
        }
    }

    for (ll x1 : fa) {
        for (ll y1 : fb) {
            ll g1 = x1 * y1;
            ll g2 = (a * b) / g1;

            ll x = a + 1;
            if (x % g1) x += g1 - (x % g1);

            ll y = b + 1;
            if (y % g2) y += g2 - (y % g2);

            if (x <= c && y <= d) {
                cout << x << " " << y << "\n";
                return;
            }
        }
    }

    cout << "-1 -1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

/*
TC: O(t * (sqrt(a) + sqrt(b) + fac(a) * fac(b)))
SC: O(fac(a) + fac(b))

where fac(a) denotes the number of factors of a.
Note : fac(a), fac(b) <= 1344
*/