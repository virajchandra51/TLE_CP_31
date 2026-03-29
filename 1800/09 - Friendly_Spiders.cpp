#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300100;
const int kMaxA = 300100;
const int oo = 1e9;
vector<int> edges[kMaxA];
int dist[kMaxA], prv[kMaxA];
bool used[kMaxA];
int prv_id[kMaxA];
int min_prime[kMaxA];
int n, a[N];
int boss[kMaxA];
int mem_id[kMaxA];
int source, dest;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mem_id[a[i]] = i;
    }
    cin >> source >> dest;
    source--; dest--;
 
    if (a[source] == a[dest]) {
        if (source == dest) {
            cout << "1\n" << source + 1 << '\n';
        } else if (a[source] == 1) {
            cout << -1;
        } else {
            cout << "2\n" << source + 1 << " " << dest + 1;
        }
        return 0;
    }
 
    fill(min_prime, min_prime + kMaxA, oo);
 
    for (int prime = 2; prime < kMaxA; prime++) {
        if (min_prime[prime] != oo) {
            continue;
        }
        min_prime[prime] = prime;
 
        if (ll(prime) * ll(prime) >= kMaxA) {
            continue;
        }
 
        for (int value = prime * prime; value < kMaxA; value += prime) {
            min_prime[value] = min(min_prime[value], prime);
        }
    }
 
    fill(boss, boss + kMaxA, -1);
 
    fill(dist, dist + kMaxA, oo);
    fill(prv, prv + kMaxA, -1);
    queue<int> pr_queue;
 
    for (int i = 0; i < n; i++) {
        bool is_need = edges[a[i]].empty();
 
        int value = a[i];
        int pre_prime = -1;
        while (value > 1) {
            int cur_prime = min_prime[value];
            if (cur_prime != pre_prime && is_need) {
                edges[a[i]].push_back(cur_prime);
            }
 
            if (cur_prime != pre_prime && i == source) {
                dist[cur_prime] = 0;
                pr_queue.push(cur_prime);
            }
 
            pre_prime = cur_prime;
            boss[cur_prime] = i;
            value /= cur_prime;
        }
    }
 
    fill(used, used + kMaxA, false);
 
    while (!pr_queue.empty()) {
        int cur_prime = pr_queue.front();
        pr_queue.pop();
 
        for (int value = cur_prime * 2; value < kMaxA; value += cur_prime) {
            if (used[value]) {
                continue;
            }
            used[value] = true;
 
            for (int next_prime : edges[value]) {
                if (dist[next_prime] == oo) {
                    dist[next_prime] = dist[cur_prime] + 1;
                    prv_id[next_prime] = mem_id[value];
                    prv[next_prime] = cur_prime;
                    pr_queue.push(next_prime);
                }
            }
        }
    }
 
    int best_dist = oo;
    int best_prime = -1;
 
    for (int prime : edges[a[dest]]) {
        if (dist[prime] < best_dist) {
            best_dist = dist[prime];
            best_prime = prime;
        }
    }
 
    if (best_dist == oo) {
        cout << -1;
        return 0;
    }
 
    vector<int> route;
 
    int cur_prime = best_prime;
    route.push_back(dest);
    route.push_back(prv_id[best_prime]);
    while (prv[cur_prime] != -1) {
        cur_prime = prv[cur_prime];
        route.push_back(prv_id[cur_prime]);
    }
 
    std::reverse(route.begin(), route.end());
    route.front() = source;
 
    cout << route.size() << '\n';
    for (int id : route) {
        cout << id + 1 << " ";
    }
 
    return 0;
}