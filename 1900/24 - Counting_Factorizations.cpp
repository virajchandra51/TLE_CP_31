#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll modpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int N = 2 * n;

    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    unordered_map<ll,int> freq;
    for (ll x : a) freq[x]++;

    auto is_prime = [&](ll x) {
        if (x < 2) return false;
        for (ll i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    };

    vector<int> primes, nonprimes;
    for (auto &[val, cnt] : freq) {
        if (is_prime(val)) primes.push_back(cnt);
        else nonprimes.push_back(cnt);
    }

    if ((int)primes.size() < n) {
        cout << 0 << "\n";
        return 0;
    }

    vector<ll> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % MOD;

    int t = primes.size();
    vector<vector<ll>> dp(t + 1, vector<ll>(n + 1, 0));
    dp[t][0] = 1;

    for (int i = t - 1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = invfact[primes[i]] * dp[i + 1][j] % MOD;
            if (j > 0)
                dp[i][j] = (dp[i][j] +
                            invfact[primes[i] - 1] * dp[i + 1][j - 1]) % MOD;
        }
    }

    ll common = fact[n];
    for (int c : nonprimes)
        common = common * invfact[c] % MOD;

    ll ans = common * dp[0][n] % MOD;
    cout << ans << "\n";
}
// Time Complexity: O(n^2 + U * sqrt(A))
//   n^2 from DP
//   U = number of distinct values (≤ 2n)
//   sqrt(A) for primality checks
//
// Space Complexity: O(n^2)