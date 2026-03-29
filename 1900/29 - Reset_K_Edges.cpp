#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> g[N];
int parent[N], depth[N];
bool used[N];
int n, k;

void dfs_mark(int u) {
    used[u] = true;
    for(int v : g[u]) {
        if(!used[v])
            dfs_mark(v);
    }
}

bool check(int H, vector<int> &order) {
    fill(used + 1, used + n + 1, false);

    int cuts = 0;

    for(int u : order) {
        if(depth[u] <= H) break;
        if(used[u]) continue;

        int v = u;
        for(int i = 0; i < H - 1; i++)
            v = parent[v];

        dfs_mark(v);
        cuts++;

        if(cuts > k)
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> k;

        for(int i = 1; i <= n; i++)
            g[i].clear();

        for(int i = 2; i <= n; i++) {
            cin >> parent[i];
            g[parent[i]].push_back(i);
        }

        // BFS to compute depth
        queue<int> q;
        q.push(1);
        depth[1] = 0;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 1);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return depth[a] > depth[b];
        });

        int low = 1, high = n, ans = n;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(mid, order)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

/*
Time Complexity: O(n log n) per testcase
Space Complexity: O(n)
*/