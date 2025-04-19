#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, x;
    cin >> n >> k >> x;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) //? O(N)
        cin >> v[i];

    sort(v.begin(), v.end()); //? O(N log N)

    vector<long long> differences;

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] - v[i] > x)
        {
            differences.push_back(v[i + 1] - v[i]);
        }
    } //? O(N)

    sort(differences.begin(), differences.end()); //? O(N log N)

    int ans = differences.size() + 1;

    for (auto difference : differences)
    {
        long long val = (difference / x) + (difference % x != 0) - 1; //! ceil(difference / x) - 1

        if (k >= val)
        {
            ans--;
            k -= val;
        }
    }

    cout << ans << "\n";
}

//! Total time complexity : O(N log N)
//! Total space complexity : O(N)