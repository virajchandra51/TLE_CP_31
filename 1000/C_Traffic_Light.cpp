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
        char color;
        cin >> color;
        string s;
        cin >> s; // n
        s += s; // n
        n *= 2;

        long long last_green_index = -1;
        long long max_seconds = INT_MIN;

        for (int i = n - 1; i >= 0; i--) // n
        {
            if (s[i] == 'g')
                last_green_index = i;
            if (s[i] == color)
            {
                long long difference = last_green_index - i;
                max_seconds = max(max_seconds, difference);
            }
        }
        cout << max_seconds << endl;
    }
    return 0;
}

// tc = O(n) = O(2*10^5)
// sc = O(n) = O(2*10^5)