#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0, count = 0;

    int l = 0, r = 0;

    while (r < k) // O(k)
    {
        if (a[r] < 2 * a[r + 1])
        {
            count++;
        }
        r++;
    }

    while (r < n) //O(n - k)
    {
        if (count == k)
        {
            ans++;
        }

        if (a[l] < 2 * a[l + 1])
        {
            count--;
        }
        if (a[r] < 2 * a[r + 1])
        {
            count++;
        }
        l++;
        r++;
    }

    cout << ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}

// TC: O(n)
// SC: O(1)