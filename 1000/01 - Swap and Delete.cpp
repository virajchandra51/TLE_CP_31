#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s; // n
        int n = s.size();
        int count_of_0s = 0, count_of_1s = 0;
        for (int i = 0; i < n; i++) // n
        {
            if (s[i] == '0')
                count_of_0s++;
            else
                count_of_1s++;
        }

        int length_of_t = 0;
        for (int i = 0; i < n; i++) // n
        {
            if (s[i] == '0' && count_of_1s > 0)
                count_of_1s--, length_of_t++;
            else if (s[i] == '1' && count_of_0s > 0)
                count_of_0s--, length_of_t++;
            else
                break;
        }

        cout << n - length_of_t << endl;
    }
    return 0;
}

// tc - O(n) = O(2*10^5)
// sc - O(n) = O(2*10^5)