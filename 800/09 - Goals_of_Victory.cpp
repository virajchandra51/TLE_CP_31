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
        for (long long i = 0; i < n - 1; i++) // n
            cin >> a[i];
        // inputs

        long long sum = 0;
        for (long long i = 0; i < n - 1; i++) // n
            sum += a[i];

        cout << -1 * sum << endl;
    }
    return 0;
}

// tc - O(n) = O(100)
// sc - O(n) = O(100)