#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)(1e9+7)
void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){//n
        cin>>a[i];
    }
    sort(a.begin(), a.end());//nlogn
    vector<int> b(n);
    for (int i = 0; i < n; i++){//n
        cin>>b[i];
    }
    sort(b.rbegin(), b.rend());//nlogn
    ll result = 1;
    for (int i = 0; i < n; i++) {//nlogn
        ll temp=upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll count = a.size() - temp;
        result = result * max(count - i, 0LL) % MOD;
    }
    cout << result << endl;
    // T.C :- O(nlogn)
    // S.C :- O(n)
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

 