#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
    int N; cin >> N;
    
    vector<int> A(N);
    for (int &x : A) cin >> x, --x;
    
    vector<int> cnt(N, 0), is_last(N, 0), last_pos(N, -1);
    for (int i = N-1; i >= 0; --i) {
        if (!cnt[A[i]]++) is_last[i] = 1, last_pos[A[i]] = i;
    }
    
    vector<int> ans;
    multiset<int> st;
    int l = 0, r = -1, flag = 0;
    while (r+1 < N) {
        while (r+1 < N and (r == -1 or !is_last[r])) {
            ++r;
            if (is_last[last_pos[A[r]]]) st.emplace(A[r]);
        }
        if (st.size()) {
            ans.emplace_back(flag ? *begin(st) : *rbegin(st)), flag ^= 1;
            is_last[last_pos[ans.back()]] = 0;
            while (A[l] != ans.back()) {
                if (auto it = st.find(A[l++]); it != end(st)) st.erase(it);
            }
            st.erase(A[l++]); // no find
        }
    }
    
    int M = ans.size();
    cout << M << '\n';
    for (int i = 0; i < M; ++i) cout << ans[i] + 1 << " \n"[i == M-1];
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t = 1; cin >> t;
    for (int _ = 1; _ <= t; ++_)
        solve();
    
    return 0;
}

// Time: O(n log n)
// Space: O(n)