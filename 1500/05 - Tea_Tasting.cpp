#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    //INPUT

    vector<int> pr(n + 1, 0);
    for (int i = 1; i <= n; i++) //n
        pr[i] = pr[i - 1] + b[i];

    vector<int> cnt(n + 2, 0), ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x = a[i] + pr[i - 1];
        auto j = upper_bound(pr.begin(), pr.end(), x) - pr.begin();
        //logn
        if (j <= n) {
            ans[j] += x - pr[j - 1];
        }
        cnt[i]++;
        cnt[j]--;
    }//nlogn
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        ans[i] += cnt[i] * b[i];
    }//n
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }//n
    cout << '\n';
}

//tc -> O(nlogn)
//sc -> O(n)

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