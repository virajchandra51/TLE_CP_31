#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n); // O(nlogn)
    int diff[n - 1]; // O(n) space
    for(int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i] - 1;
    }

    sort(diff,diff + n - 1); // O(nlogn)

    int ans = n;

    for(int i = 0; i < n - k; i++) {
        ans += diff[i];
    }

    cout << ans << '\n';
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

// TC: O(nlogn)
// SC: O(n)