#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    int b[n];

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<int,long long> poss; // O(n) space

    for(int i = 0; i < n; i++) { // O(n)
        poss[i - b[i]] += b[i]; // O(logn)
    }

    long long ans = 0;

    for(auto [x,y] : poss) { // O(n)
        ans = max(ans, y);
    }

    cout << ans << '\n';
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}

// TC: O(nlogn)
// SC: O(n)