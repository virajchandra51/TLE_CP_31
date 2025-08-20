#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s; //n

    int c1 = count(s.begin(), s.end(), '+'); //n
    int c2 = n - c1;

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (c1 == c2) {
            cout << "YES\n";
            continue;
        }
        if (a == b) {
            cout << "NO\n";
            continue;
        }
        int l = lcm(a, b); //log(max(a, b))
        int x = l / a, y = l / b;
        if (abs(c2 - c1) % abs(y - x) == 0) {
            int p = abs(c2 - c1) / abs(y - x);
            if ((x + y) * p > n) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else {
            cout << "NO\n";
        }
    } //O(q*log(max(a, b)))

    return 0;
}

//tc -> O(n + q*log(1e9)) ->  30*1e5
//sc -> O(1)