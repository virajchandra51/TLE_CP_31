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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i];

        long long mx = *max_element(a.begin(), a.end()); // n
        vector<long long> b, c;
        for (int i = 0; i < n; i++) // n
        {
            if (a[i] != mx)
                b.push_back(a[i]);
            else
                c.push_back(a[i]);
        }

        if (b.size() == 0) //  all elements are same and hence max
        {
            cout << -1 << endl;
        }
        else
        {
            cout << b.size() << " " << c.size() << endl;
            for (auto it : b) // n
                cout << it << " ";
            cout << endl;
            for (auto it : c) // n
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}

// tc - O(n) - O(100)
// sc - O(n) - O(100)