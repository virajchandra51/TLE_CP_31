#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Chunk {
    ll min_pref;
    ll sum;
};

struct Node {
    ll min_pref;
    ll sum;
    int list_id;
    int idx;

    bool operator<(const Node &other) const {
        return min_pref < other.min_pref; // max heap
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    int k;
    cin >> x >> k;

    vector<vector<Chunk>> lists(k);

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        ll sum = 0, min_pref = 0;

        for (int j = 0; j < n; j++) {
            ll w;
            cin >> w;

            sum += w;
            min_pref = min(min_pref, sum);

            if (sum > 0) {
                lists[i].push_back({min_pref, sum});
                sum = 0;
                min_pref = 0;
            }
        }
    }

    priority_queue<Node> pq;

    for (int i = 0; i < k; i++) {
        if (!lists[i].empty()) {
            pq.push({lists[i][0].min_pref, lists[i][0].sum, i, 0});
        }
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (x + cur.min_pref < 0) break;

        x += cur.sum;

        int nxt = cur.idx + 1;
        if (nxt < lists[cur.list_id].size()) {
            auto &c = lists[cur.list_id][nxt];
            pq.push({c.min_pref, c.sum, cur.list_id, nxt});
        }
    }

    cout << x << "\n";
}

/*
Let N denote the sum of sizes of all lists

Time Complexity:
O(N log K)

Space Complexity:
O(N)
storing chunks + priority queue
*/