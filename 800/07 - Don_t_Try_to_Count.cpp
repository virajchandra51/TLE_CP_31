#include <bits/stdc++.h>
using namespace std;

bool check(string s, string x)
{
    if (x.size() < s.size())
    {
        return false;
    }
    for (int i = 0; i < x.size() - s.size() + 1; i++) // n - m + 1
    {
        if (x.substr(i, s.size()) == s) // m
        {
            return true;
        }
    }
    return false;
} // O(n*m)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        string x;
        cin >> x;
        string s;
        cin >> s;
        // inputs

        string x0 = x; //  0 operations
        string x1 = x0 + x0; // 1 operation
        string x2 = x1 + x1; // 2 operations
        string x3 = x2 + x2; // 3 operations
        string x4 = x3 + x3; // 4 operations
        string x5 = x4 + x4; // 5 operations

        long long ans = -1;
        if (check(s, x0))
            ans = 0;
        else if (check(s, x1))
            ans = 1;
        else if (check(s, x2))
            ans = 2;
        else if (check(s, x3))
            ans = 3;
        else if (check(s, x4))
            ans = 4;
        else if (check(s, x5))
            ans = 5;
        cout << ans << endl;
    }
    return 0;
}

// tc - O(2^5*n*m) = O(32*n*m)
// sc - O(2^5*n) = O(32*n)