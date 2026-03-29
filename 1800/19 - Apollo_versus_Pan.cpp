#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using vi = std::vector<int>;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    vi cnt(60, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < 60; j++)
        {
            if (v[i] & (1LL << j))
            {
                cnt[j]++;
                cnt[j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j < 60; j++)
        {
            if (v[i] & (1LL << j))
            {
                sum1 += ((1LL << j) % mod) * cnt[j];
                sum2 += ((1LL << j) % mod) * n;
                sum1 %= mod;
                sum2 %= mod;
            }
            else
            {
                sum2 += ((1LL << j) % mod) * cnt[j];
                sum2 %= mod;
            }
        }
        ans += (sum1 * sum2) % mod;
        ans %= mod;
    }
    cout << ans % mod << '\n';
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
// Time Complexity: O(n * log(maxA))) where maxA is the maximum element in the array
// Space Complexity: O(log(maxA)) for the count array