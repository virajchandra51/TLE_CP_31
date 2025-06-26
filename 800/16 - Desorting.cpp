#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) // n
            cin >> a[i];
        // inputs

        long long operations = INT_MAX;
        for (int i = 0; i < n - 1; i++) // n
        {
            if (a[i] <= a[i + 1]) // sorted
            {
                long long diff = a[i + 1] - a[i]; // always positive
                long long required_operations = diff / 2 + 1;
                operations = min(operations, required_operations);
            }
            else // unsorted
                operations = 0;
        }

        cout << operations << endl;
    }
    return 0;
}

// tc - O(n) = O(500)
// sc - O(n) = O(500)