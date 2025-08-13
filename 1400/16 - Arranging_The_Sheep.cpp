#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> sheeps; // O(n) space
    
    for(int i = 0; i < n; i++) { // O(n) time
        if(s[i] == '*') {
            sheeps.push_back(i);
        }
    }
    
    int index = (sheeps.size() - 1) / 2;
    
    long long int ans = 0;
    
    for(int i = 0; i < sheeps.size(); i++) { //O(n) time
        ans += abs(sheeps[i] - (sheeps[index] - index + i));
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
// SC: O(n)