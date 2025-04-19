#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> v(m, vector<long long>(n)); //! storing a rotated matrix

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                cin >> v[i][j]; 
            }
        } //? O(n * m)

        for (int i = 0; i < m; i++)
        {
            sort(v[i].begin(), v[i].end()); //? O(n log n)
        } //? O(m * (n log n))

        long long ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans -= (v[i][j] * (n - j - 1));
                ans += (v[i][j] * j);
            }
        } //? O(n * m)

        cout << ans << "\n";
    }
}

//? Total time complexity : O(m * (n log n))
//? Total space complexity : O(n * m)