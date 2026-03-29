#include <bits/stdc++.h>
using namespace std;

const int MAXA = 300000;

// Precompute smallest prime factor for all numbers up to MAXA
vector<int> spf(MAXA + 1);
void sieve() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= MAXA; i++)
        if (spf[i] == i)
            for (int j = i * i; j <= MAXA; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

vector<int> factorize(int x) {
    vector<int> primes;
    while (x > 1) {
        int p = spf[x];
        primes.push_back(p);
        while (x % p == 0) x /= p;
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 1 << "\n" << s << "\n";
        return 0;
    }

    // For each prime, store which spiders have it
    vector<vector<int>> spiders_by_prime(MAXA + 1);
    for (int i = 1; i <= n; i++) {
        for (int p : factorize(a[i]))
            spiders_by_prime[p].push_back(i);
    }

    vector<int> dist(n + 1, -1), parent(n + 1, -1);
    vector<bool> prime_used(MAXA + 1, false);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int p : factorize(a[u])) {
            if (prime_used[p]) continue;
            prime_used[p] = true;
            for (int v : spiders_by_prime[p]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                    if (v == t) break;
                }
            }
        }
    }

    if (dist[t] == -1) {
        cout << -1 << "\n";
        return 0;
    }

    // reconstruct path
    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++)
        cout << path[i] << " \n"[i + 1 == (int)path.size()];
}

// Time Complexity: O(A * loglogA + n * log A) where A is the maximum value in array a
// Space Complexity: O(A + n * log A)