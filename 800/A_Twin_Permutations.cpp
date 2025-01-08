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

        for (int i = 0; i < n; i++) // n
        {
            cout << n + 1 - a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// tc = O(n) = O(100)
// sc = O(n) = O(100)