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
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];
        
        unordered_set<long long> s;
        for (long long i = 0; i < n; i++) // n
            s.insert(a[i]); // 1

        if (s.size() < n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// tc = O(n) = O(1000)
// sc = O(n) = O(1000)