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
        // inputs

        long long total_number_of_twos = 0;
        long long current_number_of_twos = 0;

        for (long long i = 0; i < n; i++) // n
        {
            if (a[i] == 2)
                total_number_of_twos++;
        } // before

        long long ans = -1;

        // prefix
        for (long long i = 0; i < n; i++) // n
        {
            if (a[i] == 2)
                current_number_of_twos++;

            if ((current_number_of_twos) == (total_number_of_twos - current_number_of_twos))
            {
                ans = i + 1;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

// tc - O(n) = O(1000)
// sc - O(n) = O(1000)