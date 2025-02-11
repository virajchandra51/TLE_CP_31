#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];

        map<long long, long long> mp;
        for (long long i = 0; i < n; i++) // n
            mp[a[i]]++;                   // logn

        long long current_highest_freq = 0;
        for (auto i : mp)
            current_highest_freq = max(current_highest_freq, i.second);

        long long operations = 0;
        while (current_highest_freq < n) // log2(n)
        {
            operations++; // to clone the array
            if (current_highest_freq * 2 <= n)
            {
                operations += current_highest_freq; // swap all the copies
                current_highest_freq *= 2;
            }
            else
            {
                operations += n - current_highest_freq; // swap only required copies
                current_highest_freq = n;
            }
        }

        cout << operations << endl;
    }
    return 0;
}

// tc - O(nlog2(n)) = O(10^5*log2(10^5)) = O(2*10^6)
// sc - O(n) = O(10^5)