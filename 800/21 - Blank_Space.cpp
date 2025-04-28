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
        // input

        long long count_of_zeroes = 0;
        long long maximum_length = 0;
        for (int i = 0; i < n; i++) // n
        {
            if (a[i] == 0)
                count_of_zeroes++; // counting
            else
                count_of_zeroes = 0; // reset
            
            maximum_length = max(maximum_length, count_of_zeroes);
        }
        cout << maximum_length << endl;
    }
    return 0;
}

// tc - O(n) = O(100)
// sc - O(n)