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

        map<long long, long long> frequency_map;
        for (int i = 0; i < n; i++) // n
            frequency_map[a[i]]++; // log(n)
        // nlog(n)

        if (frequency_map.size() >= 3)
        {
            cout << "No" << endl;
        }
        else
        {
            // begin - first element
            // rbegin - last element
            long long freq_1 = frequency_map.begin()->second;
            long long freq_2 = frequency_map.rbegin()->second;
            if (freq_1 == freq_2)
                cout << "Yes" << endl;
            else if (n % 2 == 1 && abs(freq_1 - freq_2) == 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}

// tc - O(nlog2n) = O(100*log2(100)) = O(100*7) = O(700)
// sc - O(n+n) = O(2n) = O(n) = O(100)