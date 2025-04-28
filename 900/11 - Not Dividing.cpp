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
        vector<int> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i];

        // n 
        for (int i = 0; i < n; i++) //  performing the first set of n operations
        {
            if (a[i] == 1)
                a[i]++;
        }

        // n
        for (int i = 0; i < n - 1; i++) //  performing the second set of n-1 operations
        {
            if (a[i + 1] % a[i] == 0)
                a[i + 1]++;
        }

        // n
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}

// tc - O(n) = O(10^4)
// sc - O(n) = O(10^4)