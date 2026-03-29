#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    vector<int> L(n);
    vector<int> R(n);

    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
        L[i] = segments[i].first;
        R[i] = segments[i].second;
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    int ans = n;
    for (int i = 0; i < n; ++i) {
        int l = segments[i].first;
        int r = segments[i].second;

        int deletions_left = lower_bound(R.begin(), R.end(), l) - R.begin();
        int deletions_right = L.end() - upper_bound(L.begin(), L.end(), r);
        int current_deletions = deletions_left + deletions_right;
        ans = min(ans, current_deletions);
    }

    cout << ans  << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// Time Complexity: O(n log n)
// Space Complexity: O(n)