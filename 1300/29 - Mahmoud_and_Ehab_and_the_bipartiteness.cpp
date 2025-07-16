#include<bits/stdc++.h>
using namespace std;

int red = 0, white = 0;

void dfs(int node, int color, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node]++;
    if (color == 1) red++;
    else white++;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, 1 - color, adj, visited); // Alternate colors
        }
    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> visited(n, 0);
    for(int i = 0; i < n-1; i++){ //O(n)
        int u, v; cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0, adj, visited); //O(n)

    cout << 1LL * red * white - (n - 1) << endl;
    return 0;
}

// TC = O(n)
// SC = O(n)