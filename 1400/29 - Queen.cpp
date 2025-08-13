#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<bool> good(n); // O(n) space
    vector<vector<int>> adj(n); // O(n) space

    for(int i = 0; i < n; i++) {
        int parent, type;
        cin >> parent >> type;
        if(type == 0) good[i] = true;
        if(parent != -1) {
            adj[parent - 1].push_back(i);
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) { // O(n)
        if(good[i]) continue;
        bool flag = true;
        for(auto x : adj[i]) { // O(E)
            if(good[x]) flag = false;
        }
        if(flag) ans.push_back(i + 1);
    }

    if(ans.size()) {
        for(auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}

// TC: O(n)
// SC: O(n)