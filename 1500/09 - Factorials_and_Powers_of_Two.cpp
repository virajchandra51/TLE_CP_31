#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = 1e18;

int setbits(int n) { return __builtin_popcountll(n); }

void solve() {
    int n;
    cin >> n;

    vector<int> fact(15);
    fact[0] = 1;
    for (int i = 1; i <= 14; i++)
        fact[i] = fact[i - 1] * i; //O(14)

    vector<int> vec;
    for (int i = 3; i <= 14; i++)
        vec.push_back(fact[i]); //O(12)

    int ans = INF;
    for (int mask = 0; mask < (1LL << 12); mask++) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < 12; i++) {
            if (mask & (1LL << i)) {
                sum += vec[i];
                cnt++;
            }
        } //O(12)
        if (sum > n)
            continue;
        cnt += setbits(n - sum); //O(logn)
        ans = min(ans, cnt);
    }//O(2^12*logn)

    cout << ans << '\n';
}

//tc : O(logn*2^12*t) -> 40*4e3*100 -> 1.6e7
//sc : O(14)

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}