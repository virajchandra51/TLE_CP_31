#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(4, 0));
    for(int i = 0; i < n; i++) { //O(n)
        dp[i][0] = 1; 
    }

    for(int i = 1; i<n; i++){ //O(n)
        if(s[i] =='v' and s[i-1] == 'v'){
            // case of w
            dp[i+1][1] += dp[i-1][0];
            dp[i+1][3] += dp[i-1][2];
        }
        else if(s[i] == 'o'){
            dp[i+1][2] += dp[i][1];
        }
        dp[i+1][1] += dp[i][1]; 
        dp[i+1][2] += dp[i][2];
        dp[i+1][3] += dp[i][3];
    }
    cout<< dp[n][3] << endl; // Total number of "wow" substrings
    return 0;
}

// TC = O(n)
// SC = O(n)