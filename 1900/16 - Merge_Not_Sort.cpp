#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> C(2*N);
    for (int &x : C) cin >> x;

    // build chunks
    vector<vector<int>> chunks;
    chunks.push_back({C[0]});

    for (int i = 1; i < 2*N; i++) {
        if (C[i] < chunks.back()[0]) {
            chunks.back().push_back(C[i]);
        } else {
            chunks.push_back({C[i]});
        }
    }

    int k = chunks.size();

    vector<int> len(k);
    for (int i = 0; i < k; i++) len[i] = chunks[i].size();

    // subset sum DP
    vector<vector<bool>> dp(k+1, vector<bool>(N+1,false));
    vector<vector<bool>> take(k+1, vector<bool>(N+1,false));

    dp[0][0] = true;

    for (int i = 1; i <= k; i++) {
        for (int s = 0; s <= N; s++) {
            if (dp[i-1][s]) {
                dp[i][s] = true;
            }
            if (s >= len[i-1] && dp[i-1][s-len[i-1]]) {
                dp[i][s] = true;
                take[i][s] = true;
            }
        }
    }

    if (!dp[k][N]) {
        cout << -1 << "\n";
        return 0;
    }

    // reconstruct
    vector<int> choose(k);
    int s = N;

    for (int i = k; i >= 1; i--) {
        if (take[i][s]) {
            choose[i-1] = 1;
            s -= len[i-1];
        }
    }

    vector<int> A, B;

    for (int i = 0; i < k; i++) {
        if (choose[i]) {
            for (int x : chunks[i]) A.push_back(x);
        } else {
            for (int x : chunks[i]) B.push_back(x);
        }
    }

    for (int x : A) cout << x << " ";
    cout << "\n";

    for (int x : B) cout << x << " ";
    cout << "\n";
}

// TC : O(n^2)
// SC : O(n^2)