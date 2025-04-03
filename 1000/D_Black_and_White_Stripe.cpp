#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        string s; 
        cin >> s; // n
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) // n
            prefix[i + 1] = prefix[i] + (s[i] == 'W');

        long long minimum_cells = INT_MAX;
        for (int i = 0; i <= n - k; i++) // n
        {
            long long diff = prefix[i + k] - prefix[i];
            minimum_cells = min(minimum_cells, diff);
        }

        cout << minimum_cells << endl;
    }
    return 0;
}

// tc = O(n) = O(2*10^5)
// sc = O(n) = O(2*10^5)