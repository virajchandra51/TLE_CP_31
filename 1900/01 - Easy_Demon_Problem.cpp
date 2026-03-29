#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LIM = 200000;
const int SZ  = 2 * LIM + 1;
vector<bool> hasU(SZ, false), hasV(SZ, false);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> a(n), b(m);
    ll A = 0, B = 0;

    for (int i = 0; i < n; i++) cin >> a[i], A += a[i];
    for (int j = 0; j < m; j++) cin >> b[j], B += b[j];

    for (int i = 0; i < n; i++) {
        ll u = A - a[i];
        if (llabs(u) <= LIM) hasU[u + LIM] = true;
    }
    for (int j = 0; j < m; j++) {
        ll v = B - b[j];
        if (llabs(v) <= LIM) hasV[v + LIM] = true;
    }

    auto check = [&](ll d, ll e, ll x, bool &ok) {
        if (llabs(d) > LIM || llabs(e) > LIM) return;
        if(d * e != x ) return;
        if(hasU[d + LIM] && hasV[e + LIM]) { ok = true; }
    };

    while (q--) {
        ll x;
        cin >> x;

        ll ax = llabs(x);
        bool ok = false;

        for (ll d = 1; d * d <= ax && !ok; d++) {
            if (ax % d) continue;

            ll e = ax / d;

            // Now we test all sign patterns
            check(d, e, x, ok);
            check(e, d, x, ok);
            check(-d, -e, x, ok);
            check(-e, -d, x, ok);
            check(d, -e, x, ok);
            check(-d, e, x, ok);
            check(e, -d, x, ok);
            check(-e, d, x, ok);
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}

/*
TC:
 - Build U, V: O(n + m)
 - Each query: O(sqrt(|x|)) <= 450 checks, each O(1)
 - Total - O(n + m + q * sqrt(|x|))

SC:
 - O(maxX) for boolean arrays + O(n+m) input.
*/