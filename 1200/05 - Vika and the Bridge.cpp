#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; i++) //! O(N)
            cin >> v[i];

        vector<int> colours[k + 1];

        for (int i = 1; i <= k; i++) //! O(k)
        {
            colours[i].push_back(0);
        }

        for (int i = 0; i < n; i++) //! O(N)
        {
            colours[v[i]].push_back(i + 1);
        }

        for (int i = 1; i <= k; i++) //! O(k)
        {
            colours[i].push_back(n + 1);
        }

        priority_queue<int> jumps[k + 1];

        int ans = INT_MAX;

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < colours[i].size() - 1; j++)
            {
                jumps[i].push(colours[i][j + 1] - colours[i][j] - 1);
            } //! x -> O(x log x)

            int max_val = jumps[i].top();

            jumps[i].pop();

            if (max_val % 2 == 0)
            {
                jumps[i].push(max_val / 2);
                jumps[i].push((max_val / 2) - 1);
            }
            else
            {
                jumps[i].push(max_val / 2);
                jumps[i].push(max_val / 2);
            }

            ans = min(ans, jumps[i].top());
        } //! O(N log N)

        cout << ans << "\n";
    }

    return 0;
}

//! Total time complexity : O(K + N log N) -> O(N log N)
//! Total space complexity : O(N)