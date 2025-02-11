#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long test;
    cin >> test;
    while (test--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();

        vector<int> frequency_in_t(26, 0);
        for (int i = 0; i < m; i++) // m
            frequency_in_t[t[i] - 'A']++;

        for (int i = n - 1; i >= 0; i--) // n
        {
            if (frequency_in_t[s[i] - 'A'] > 0)
                frequency_in_t[s[i] - 'A']--;
            else
                s[i] = '.';
        }

        string final_string = "";

        for (int i = 0; i < n; i++) // n
        {
            if (s[i] != '.')
                final_string += s[i];
        }

        if (final_string == t) // m
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// tc = O(n+m) = O(30)
// sc = O(n+m+26+m) = O(n+m) = O(30)