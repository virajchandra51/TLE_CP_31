#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int fr[n]{};
    for (int i = 0; i < n; i++) // O(n)
    {
        int temp;
        cin >> temp;
        fr[temp - 1]++;
    }
    sort(fr, fr + n, greater<>()); // O(nlogn)
    int last = INT_MAX;
    long long ans = 0;
    for (int i = 0; i < n && last > 0; i++) // O(n)
    {
        if (fr[i] >= last)
        {
            ans += last - 1;
            last--;
        }
        else
        {
            ans += fr[i];
            last = fr[i];
        }
    }

    cout << ans << '\n';
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

// TC: O(nlogn)
// SC: O(n)