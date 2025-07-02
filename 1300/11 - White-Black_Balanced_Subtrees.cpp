#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int dfs(int node, vector<vector<int>>& adj, string& s){
    if(adj[node].size() == 0) {
        return s[node-1] == 'W' ? 1 : -1;
    }
    int count = 0;
    for(auto child : adj[node]) {
        count += dfs(child, adj, s);
    }
    count += (s[node-1] == 'W' ? 1 : -1);
    if(count == 0) {
        ans++;
    }
    return count;
}

int main(){
    int t; cin>>t;
    while(t--){
        ans = 0;
        int n; cin>>n;
        vector<vector<int>> adj(n+1, vector<int>());
        for(int i = 0; i < n-1; i++) { //O(n)
            int temp; cin>>temp;
            adj[temp].push_back(i+2);
        }
        string s; cin >> s;
        dfs(1, adj, s); //O(n)
        cout << ans << endl;
    }
}

// TC = O(n)
// SC = O(n)