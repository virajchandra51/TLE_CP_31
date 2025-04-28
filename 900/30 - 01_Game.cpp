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

        int count_of_one = 0;
        int count_of_zero = 0;
        for (int i = 0; i < s.length(); i++) // n
        {
            if (s[i] == '0')
                count_of_zero++;
            else
                count_of_one++;
        }

        int operations = min(count_of_zero, count_of_one);
        if (operations % 2 != 0)
            cout << "DA" << endl;
        else
            cout << "NET" << endl;
    }
    return 0;
}

// tc - O(n) = O(100)
// sc - O(n) = O(100)