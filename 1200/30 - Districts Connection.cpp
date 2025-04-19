#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> gang(n + 1); //! array a
        for (int i = 1; i <= n; i++)
            cin >> gang[i]; //? O(N)

        vector<array<int, 2>> edges;

        int val1 = 1, val2 = -1; //! first 2 nodes to be connected by an edge
        for (int i = 2; i <= n; i++)
        {
            if (gang[i] != gang[1])
            {
                edges.push_back({1, i});
                val2 = i;
                break;
            }
        } //? O(N)

        if (val2 == -1)
        {
            cout << "NO\n";
            continue;
        }

        for (int i = 2; i <= n; i++)
        {
            if (i == val2)
                continue;

            if (gang[i] != gang[val1])
            {
                edges.push_back({val1, i});
            }
            else
            {
                edges.push_back({val2, i});
            }
        } //? O(N)

        cout << "YES\n";

        for (auto &edge : edges)
        {
            cout << edge[0] << " " << edge[1] << "\n";
        }
    }

    return 0;
}

//! Total time complexity : O(N)
//! Total space complexity : O(N)