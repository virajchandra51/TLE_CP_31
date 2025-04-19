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

        vector<long long> second_elements;
        long long lowest_first_minimum = INT_MAX;

        for (int i = 0; i < n; i++) // n
        {
            long long m;
            cin >> m;
            vector<long long> a(m);
            for (auto &x : a) // m
                cin >> x;
            
            sort(a.begin(), a.end()); // mlogm
            
            second_elements.push_back(a[1]);
            lowest_first_minimum = min(lowest_first_minimum, a[0]);
        }

        sort(second_elements.begin(), second_elements.end());

        long long sum_of_second_elements = accumulate(second_elements.begin(), second_elements.end(), 0LL);
        long long lowest_second_minimum = second_elements[0];

        long long answer = lowest_first_minimum + sum_of_second_elements - lowest_second_minimum;
        cout << answer << endl;
    }
    return 0;
}

// tc = O(mlogm) = O(50000*log2(500000)) = O(50000*19) = O(950000) = O(10^6)
// sc = O(m) = O(50000) = O(10^5)