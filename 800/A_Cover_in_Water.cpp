#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // inputs

        bool continuous_three_empty_cells = false;
        int total_count_of_empty_cells = 0;

        for (int i = 0; i < n; i++) // n
        {
            if (s[i] == '.' && i + 1 < n && s[i + 1] == '.' && i + 2 < n && s[i + 2] == '.')
            {
                continuous_three_empty_cells = true;
                break;
            }
            if (s[i] == '.')
                total_count_of_empty_cells++;
        }

        if (continuous_three_empty_cells)
            cout << 2 << endl;
        else
            cout << total_count_of_empty_cells << endl;
    }
    return 0;
}

// tc - O(n) = O(100)
// sc - O(n) = O(100)