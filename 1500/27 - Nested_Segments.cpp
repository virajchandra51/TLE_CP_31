#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r, i + 1};
    } // n

    sort(a.begin(), a.end(), [&](vector<int> &v1, vector<int> &v2) {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }); // nlogn

    int mx = a[0][1], ind = a[0][2];
    for (int i = 1; i < n; i++) {
        if (mx >= a[i][1]) {
            cout << a[i][2] << ' ' << ind << '\n';
            return 0;
        }
        if (a[i][1] > mx) {
            mx = a[i][1];
            ind = a[i][2];
        }
    } // n
    cout << "-1 -1\n";

    return 0;
}

// tc : O(nlogn)
// sc : O(n)