#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        if (s[0] != s[n - 1])
        {
            if (s[0] == 'a')
                s[0] = 'b';
            else
                s[0] = 'a';
        }

        cout << s << endl;
    }
    return 0;
}

// tc - O(n) = O(100)
// sc - O(n) = O(100)