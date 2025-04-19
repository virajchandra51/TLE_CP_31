#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<vector<long long> > a(n, vector<long long>(m));
        for (long long i = 0; i < n; i++)
            for (long long j = 0; j < m; j++)
                cin >> a[i][j];

        long long negatives = 0;
        long long minimum = INT_MAX;
        long long sum = 0;

        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < m; j++)
            {
                if (a[i][j] < 0)
                    negatives++;
                minimum = min(minimum, abs(a[i][j]));
                sum += abs(a[i][j]);
            }
        }
        if (negatives % 2 == 0)
            cout << sum << endl;
        else
            cout << sum - 2 * abs(minimum) << endl;
    }
}

// tc = O(n*m) = O(100)
// sc = O(n*m) = O(100)