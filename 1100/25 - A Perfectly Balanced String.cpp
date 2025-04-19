#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;//n
    int n = (int)s.size();
    set<char> c;
    int k;
    for (k = 0; k < n; k++)//nlogn
    {
        if (c.find(s[k]) == c.end()) {
            c.insert(s[k]);
        }
        else {
            break;
        }
    }
    for (int i = k; i < n; i++)//n
    {
        if (s[i] != s[i - k]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
// T.C :- O(nlogn)
// S.C :- O(n)

 


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

 