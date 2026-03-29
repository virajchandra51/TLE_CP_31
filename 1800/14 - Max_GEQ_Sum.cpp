#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

using ll = long long;
const ll INF = numeric_limits<ll>::min();

struct SegmentTree {
    int n;
    vector<ll> tree;

    SegmentTree(const vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<ll>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2 * v + 1, tl, tm);
            build(arr, 2 * v + 2, tm + 1, tr);
            tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }

    ll query(int l, int r) {
        if (l > r) return INF;
        return query_recursive(0, 0, n - 1, l, r);
    }

    ll query_recursive(int v, int tl, int tr, int l, int r) {
        if (l > r) return INF;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return max(
            query_recursive(2 * v + 1, tl, tm, l, min(r, tm)),
            query_recursive(2 * v + 2, tm + 1, tr, max(l, tm + 1), r)
        );
    }
};

string solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> x(n, -1), y(n, n);
    stack<int> s_pge, s_nge;

    for (int i = 0; i < n; ++i) {
        while (!s_pge.empty() && a[s_pge.top()] <= a[i]) s_pge.pop();
        if (!s_pge.empty()) x[i] = s_pge.top();
        s_pge.push(i);
    }

    for (int i = n - 1; i >= 0; --i) {
        while (!s_nge.empty() && a[s_nge.top()] < a[i]) s_nge.pop();
        if (!s_nge.empty()) y[i] = s_nge.top();
        s_nge.push(i);
    }

    vector<ll> ps(n + 1, 0), ss(n + 1, 0);
    for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] + a[i];
    for (int i = n - 1; i >= 0; --i) ss[i] = ss[i + 1] + a[i];

    SegmentTree ps_tree(ps);
    SegmentTree ss_tree(ss);

    for (int k = 0; k < n; ++k) {
        int l = x[k] + 1;
        int r = y[k] - 1;

        ll max_suffix_val = ss_tree.query(l, k);
        if (max_suffix_val > a[k] + ss[k + 1]) return "NO";

        ll max_prefix_val = ps_tree.query(k + 1, r + 1);
        if (max_prefix_val > a[k] + ps[k]) return "NO";
    }

    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--)
        cout << solve() << endl;

    return 0;
}

// Time Complexity: O(n log n) per test case due to segment tree queries.
// Space Complexity: O(n) for storing arrays and segment trees.