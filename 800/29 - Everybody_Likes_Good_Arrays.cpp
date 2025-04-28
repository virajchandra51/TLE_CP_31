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
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];
        // inout

        long long operations_count = 0;

        for (long long i = 0; i < n - 1; i++) // n
        {
            if ((a[i] % 2) == (a[i + 1] % 2)) // 1
                operations_count++;
        }
        cout << operations_count << endl;
    }
    return 0;
}

// tc - O(n) = O(100)
// sc - O(n) = O(100)