#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i; // n

    int sum = accumulate(a.begin(), a.end(), 0LL); // n
    int mx = *max_element(a.begin(), a.end());     // n

    if (sum % 2 || mx > sum - mx)
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}

// tc : O(n)
// sc : O(n)