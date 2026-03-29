#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;

        vector<string> a(2);
        for(auto &i : a) cin >> i;

        map<pair<int,int>,int> dp;

        auto winner = [&](pair<int,int>A, pair<int,int>B, pair<int,int>C) -> int {
            return ((a[A.first][A.second] == 'A') + (a[B.first][B.second] == 'A') + (a[C.first][C.second] == 'A') >= 2);
        };

        function<int(int, int)>f = [&](int i, int j) -> int {
            if(i >= n || j >= n) return 0;
            if(dp.count({i, j})) return dp[{i, j}];

            int option1 = (max(i + 2, j + 2) < n ? winner({0, i}, {0, i + 1}, {0, i + 2}) + winner({1, j}, {1, j + 1}, {1, j + 2}) + f(i + 3, j + 3) : 0);
            int option2 = ((i == j || i + 1 == j) ? winner({0, i}, {1, j}, {0, i + 1}) + f(i + 2, j + 1) : 0);
            int option3 = ((i == j || i == j + 1) ? winner({0, i}, {1, j}, {1, j + 1}) + f(i + 1, j + 2) : 0);
            return dp[{i, j}] = max({option1, option2, option3});
        };

        cout << f(0, 0) << endl;
    }
}
// Time Complexity - O(nlogn)
// Space Complexity - O(n)