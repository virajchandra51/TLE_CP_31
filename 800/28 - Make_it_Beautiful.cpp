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

        sort(a, a + n); // nlogn
        long long max_number = a[n - 1];
        long long min_number = a[0];
        if (max_number == min_number)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << max_number << " ";
            for (int i = 0; i < n - 1; i++) // n
                cout << a[i] << " ";
            cout << endl;
        }
    }
    return 0;
}

// tc : O(nlogn) + O(n) = O(nlogn) = O(50) = O(50*log2(50)) = O(50*6) = O(300)
// sc : O(n) = O(50)