#include <bits/stdc++.h>
using namespace std;

vector<int> fr;

bool check(int n, int m, int t) { //O(n)
    long long maxPossible = 0;
    
    for(int i = 0; i < n; i++) {
        if(t < fr[i]) {
            maxPossible += t;
        }
        else {
            maxPossible += fr[i] + (t - fr[i]) / 2;
        }
    }
    
    return maxPossible >= m;
}

void solve() {
    int n,m;
    cin >> n >> m;
    fr.assign(n,0);
    for(int i = 0; i < m; i++) { //O(m)
        int temp;
        cin >> temp;
        fr[temp-1]++;
    }
    
    int low = 0, high = 2 * m;
    
    while(low < high) { //O(logm)
        int mid = (low + high) / 2;
        if(check(n, m, mid)) { // O(n)
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    
    cout << low << '\n';
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

//TC: O(nlogm + m)
//SC: O(n)