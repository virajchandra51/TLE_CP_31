#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> dp; // O(n) space
map<pair<int,int>,int> ind; // O(n) space

void dfs(int vert, int par) {
    for(auto x : adj[vert]) {
        if(x == par) continue;

        if(ind[{par, vert}] < ind[{vert,x}]) {
            dp[x] = dp[vert];
        }
        else{
            dp[x] = 1 + dp[vert];
        }
        dfs(x,vert);
    }
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n,vector<int>());
    dp.assign(n,0);
    ind.clear();

    for(int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ind[{a,b}] = i;
        ind[{b,a}] = i;
    }

    ind[{-1,0}] = -1;

    dp[0] = 1;
    dfs(0,-1); // O(nlogn) time

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}

// TC: O(nlogn)
// SC: O(n)