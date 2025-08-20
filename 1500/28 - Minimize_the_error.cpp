#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    // INPUT

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(abs(a[i] - b[i])); // logn
    } // nlogn
    int k = k1 + k2;
    while (k > 0) {
        int x = pq.top();
        pq.pop();
        if (x == 0)
            break;
        k--;
        x--;
        pq.push(x); // logn
    } //(k1+k2)*logn

    int ans = 0;
    while (pq.size()) {
        ans += pq.top() * pq.top();
        pq.pop();
    } // n
    if (k % 2)
        ans++;
    cout << ans << '\n';

    return 0;
}

// tc : O((n + k1 + k2) * logn)
// sc : O(n)