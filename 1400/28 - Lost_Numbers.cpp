#include <bits/stdc++.h>

using namespace std;

int query(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int common(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first || a.first == b.second) return a.first;
    else return a.second;
}

int other(pair<int,int> p, int a) {
    if(p.first == a) return p.second;
    else return p.first;
}

void solve() {
    vector<int> arr = {4,8,15,16,23,42};
    int n = arr.size();
    map<int,pair<int,int>> m;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            m[arr[i] * arr[j]] = {arr[i], arr[j]};
        }
    }

    vector<int> ans(6);
    auto p1 = m[query(0,1)];
    auto p2 = m[query(1,2)];
    ans[1] = common(p1,p2);
    ans[0] = other(p1,ans[1]);
    ans[2] = other(p2,ans[1]);
    p1 = m[query(3,4)];
    p2 = m[query(4,5)];
    ans[4] = common(p1,p2);
    ans[3] = other(p1, ans[4]);
    ans[5] = other(p2, ans[4]);

    cout << "! ";
    for(auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    solve();
}

// TC: O(1)
// SC: O(1)