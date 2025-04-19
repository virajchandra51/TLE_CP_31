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

        vector<int> v(n);
        for (int i = 0; i < n; i++) //? O(N)
            cin >> v[i];

        if (v[n - 2] > v[n - 1])
        {
            cout << "-1\n";
            continue;
        }
        else if (v[n - 1] >= 0)
        {
            cout << n - 2 << "\n";
            for (int i = 1; i <= n - 2; i++) //? O(N)
            {
                cout << i << " " << n - 1 << " " << n << "\n";
            }
        }
        else
        {
            if (is_sorted(v.begin(), v.end())) //? O(N)
                cout << "0\n";
            else
                cout << "-1\n";
        }
    }

    return 0;
}

//! Total time complexity : O(N)
//! Total space complexity : O(N)