#include <bits/stdc++.h>
using namespace std;

const int MAX_COLOUR = 100000;

//Takes O(nlogn) time where n is the size of vector v
long long calculateSumOfAllPairs(vector<int>& v) {
    sort(v.begin(), v.end(), greater<>());
    int n = v.size();
    
    long long sum = 0;
    
    for(int i = 0, j = n-1; i < n; i++, j -= 2) {
        sum += 1LL * j * v[i];
    }
    
    return sum;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    
    vector<vector<int>> x(MAX_COLOUR); // Total O(n * m) space
    vector<vector<int>> y(MAX_COLOUR); // Total O(n * m) space
    
    for(int i = 0; i < n; i++) {       //O(n * m) time
        for(int j = 0; j < m; j++) {
            x[a[i][j]].push_back(i);
            y[a[i][j]].push_back(j);
        }
    }
    
    long long ans = 0;
    
    for(int colour = 0; colour < MAX_COLOUR; colour++) { //Total O(nm * log(nm)) time
        ans += calculateSumOfAllPairs(x[colour]);
        ans += calculateSumOfAllPairs(y[colour]);
    }
    
    cout << ans;
}

// Time complexity: O(nm * log(nm))
// Space complexity O(n * m)