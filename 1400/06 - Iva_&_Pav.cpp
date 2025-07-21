#include <bits/stdc++.h>

using namespace std;

int a[200000];
int pre[30][200001];

int range_and(int l, int r) // returns the bitwise AND of all elements from a[l] to a[r]
{
    int ans = 0;
    for (int i = 0; i < 30; i++) // O(logA)
    {
        if (pre[i][r + 1] - pre[i][l] == 0)
        {
            ans += (1 << i);
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int j = 0; j < 30; j++) // O(logA)
    {
        pre[j][0] = 0;
        for (int i = 0; i < n; i++) // O(n)
        {
            if ((1 << j) & a[i])
            {
                pre[j][i + 1] = pre[j][i];
            }
            else
            {
                pre[j][i + 1] = pre[j][i] + 1;
            }
        }
    }

    int q;
    cin >> q;

    while (q--) // O(q)
    {
        int l, k;
        cin >> l >> k;
        l--;

        if (a[l] < k)
        {
            cout << -1 << ' ';
            continue;
        }

        int low = l, high = n - 1;
        while (low < high) // O(logn)
        {
            int mid = (low + high + 1) / 2;
            if (range_and(l, mid) >= k) // O(logA)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << low + 1 << ' ';
    }
    cout << '\n';
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

// TC: O(n * logA + q * logn * logA)
// SC: O(n * logA)