#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> s(n);
    int odd = 0;
    for (auto &x : s)
    {
        cin >> x;
        odd += (x % 2);
    }
    int even = n - odd;

    // |U|
    long long U = ((c + 1) * (c + 2)) / 2;

    // |A|
    long long A = 0;
    for (long long val : s)
        A += (1 + val / 2);

    // |B|
    long long B = 0;
    for (long long val : s)
        B += (c - val + 1);

    // |A ∩ B|
    long long AB = ((odd + 1) * (odd)) / 2 + ((even + 1) * (even)) / 2;

    long long ans = U - A - B + AB;
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/