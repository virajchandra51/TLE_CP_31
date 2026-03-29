#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n), SUM(n), XOR(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        SUM[i] = (i) ? (v[i] + SUM[i - 1]) : v[i];
        XOR[i] = (i) ? (v[i] ^ XOR[i - 1]) : v[i];
    }
    int ans = SUM.back() - XOR.back();
    int l = 0;
    int r = n - 1;
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        if (ans == 0)
        {
            cout << "1 1" << endl;
            return;
        }
        int p1, p2;
        p1 = p2 = L;
        while (p1 <= R && p2 <= R)
        {
            int v1 = SUM[p2] - ((p1) ? (SUM[p1 - 1]) : 0);
            int v2 = XOR[p2] ^ ((p1) ? (XOR[p1 - 1]) : 0);
            int val = v1 - v2;
            if (val == ans && (p2 - p1) < (r - l))
            {
                r = p2;
                l = p1;
            }
            if (val < ans)
                p2++;
            else
                p1++;
        }
        cout << l + 1 << " " << r + 1 << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

// Time Complexity - O(n)
// Space Complexity - O(n)