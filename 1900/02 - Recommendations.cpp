#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll,ll>> l_order(n);
        for (int i = 0; i < n; ++i) cin >> l_order[i].first >> l_order[i].second;
        map<pair<ll,ll>, int> index;
        for (int i = 0; i < n; ++i) index[l_order[i]] = i;

        // sort by l asc, r desc
        sort(l_order.begin(), l_order.end(), [](const pair<ll,ll> &A, const pair<ll,ll> &B){
            if (A.first != B.first) return A.first < B.first;
            return A.second > B.second;
        });

        // sort by r desc, l asc
        vector<pair<ll,ll>> r_order = l_order;
        sort(r_order.begin(), r_order.end(), [](const pair<ll,ll> &A, const pair<ll,ll> &B){
            if (A.second != B.second) return A.second > B.second;
            return A.first < B.first;
        });

        vector<ll> ans_l(n, 0);
        vector<ll> ans_r(n, 0);
        set<ll> l_set, r_set;

        for (int i = 0; i < n; i++)
        {
            ll l = l_order[i].first;
            ll r = l_order[i].second;
            // Find smallest r' in r_set such that r' >= r
            auto it = r_set.lower_bound(r);
            if (it != r_set.end()) {
                ans_l[index[{l, r}]] = *it - r;
            }
            r_set.insert(r);
        }

        for (int i = 0; i < n; i++)
        {
            ll l = r_order[i].first;
            ll r = r_order[i].second;
            // Find largest l' in l_set such that l' <= l
            auto it = l_set.upper_bound(l);
            if (it != l_set.begin()) {
                --it;
                ans_r[index[{l, r}]] = l - *it;
            }
            l_set.insert(l);
        }
        
        
        for (int i = 0; i < n; ++i) {
            cout << ans_l[i] + ans_r[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

// TC : O(N log N)
// SC : O(N)