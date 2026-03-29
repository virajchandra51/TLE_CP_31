#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        vector<int> pos(n,0);
        iota(pos.begin(), pos.end(), 0);
        vector<pair<int, int>> ans;
        for (int i = n - 1; i; --i) {
            vector<int> occ(i, -1);
            for (auto j : pos) {
                if (occ[a[j] % i] != -1) {
                    ans.push_back({j, occ[a[j] % i]});
                    pos.erase(find(pos.begin(), pos.end(), j));
                    break;
                }
                occ[a[j] % i] = j;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
    }
}

// Time complexity : O(n^2)
// Space complexity : O(n)