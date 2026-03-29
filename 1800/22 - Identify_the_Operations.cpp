#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), pos(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            --a[i];
            pos[a[i]] = i;
        }

        set<int> s;
        vector<int> b(k);
        for (int i = 0; i < k; ++i)
        {
            cin >> b[i];
            --b[i];
            s.insert(b[i]);
        }
        long long ans = 1;
        for (auto &&i : b)
        {
            int p = pos[i];
            int cnt = 0, poss = 0;
            if (p > 0)
            {
                cnt += (s.find(a[p - 1]) != s.end());
                ++poss;
            }
            if (p < n - 1)
            {
                cnt += (s.find(a[p + 1]) != s.end());
                ++poss;
            }
            ans = ans * (poss - cnt);
            ans %= MOD;
            s.erase(i);
        }
        cout << ans << '\n';
    }
    return 0;
}

// Time Complexity: O((n + k) log n)
// Space Complexity: O(n)