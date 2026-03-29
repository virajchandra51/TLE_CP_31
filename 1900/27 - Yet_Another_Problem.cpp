#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n+1), px(n+1, 0), nz(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        px[i] = px[i-1] ^ a[i];
        nz[i] = nz[i-1] + (a[i] != 0);
    }

    unordered_map<int, vector<int>> even, odd;

    for(int i = 0; i <= n; i++) {
        if(i % 2 == 0)
            even[px[i]].push_back(i);
        else
            odd[px[i]].push_back(i);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        // XOR must be zero
        if((px[r] ^ px[l-1]) != 0) {
            cout << -1 << "\n";
            continue;
        }

        // already zero
        if(nz[r] - nz[l-1] == 0) {
            cout << 0 << "\n";
            continue;
        }

        int len = r - l + 1;

        // odd length
        if(len % 2 == 1) {
            cout << 1 << "\n";
            continue;
        }

        // shrink from boundaries
        if(a[l] == 0 || a[r] == 0) {
            cout << 1 << "\n";
            continue;
        }

        // check split
        auto &vec = (l % 2 == 0 ? even[px[l-1]] : odd[px[l-1]]);
        auto it = lower_bound(vec.begin(), vec.end(), l);

        if(it != vec.end() && *it <= r-1)
            cout << 2 << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}

/*
Time Complexity: O((n + q) log n)
Space Complexity: O(n)
*/