#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    //nearestEnemy on the left
    vector<int> nearestEnemy(n+1, 0); // O(n) space
    
    for(int i = 0; i < m; i++) { // O(m) time
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        nearestEnemy[b] = max(nearestEnemy[b], a);
    }
    
    //how much left can we go from index i? 
    vector<int> maxLeft(n+1); // O(n) space
    
    maxLeft[1] = 1;
    
    long long ans = 1; // to account for the subarray [1,1]
    
    for(int i = 2; i <= n; i++) { // O(n) time
        maxLeft[i] = max(maxLeft[i-1], nearestEnemy[i] + 1);
        ans += i - maxLeft[i] + 1;
    }
    
    cout << ans << '\n';
}

int main() {
    
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}

// TC: O(n + m)
// SC: O(n)