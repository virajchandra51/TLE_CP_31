#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    int x = INT_MAX, y = INT_MAX; // O(1) space
    
    for(int i = 0; i < n; i++) { // O(n) time
        if(x > y) {
            swap(x,y);
        }
        //x <= y
        if(a[i] <= x) // Case 1
        {
            x = a[i];
        }
        else if(a[i] <= y) { // Case 3
            y = a[i];
        }
        else { // Case 2
            x = a[i];
            ans++;
        }
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

// TC: O(n)
// SC: O(1)