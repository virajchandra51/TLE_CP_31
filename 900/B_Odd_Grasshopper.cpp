#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long start, jumps;
        cin >> start >> jumps;

        long long final_pos;
        if (jumps % 4 == 1)
            final_pos = -jumps;
        else if (jumps % 4 == 2)
            final_pos = 1;
        else if (jumps % 4 == 3)
            final_pos = jumps + 1;
        else if (jumps % 4 == 0)
            final_pos = 0;

        if (start % 2 == 0)
            final_pos = start + final_pos;
        else
            final_pos = start - final_pos;

        cout << final_pos << endl;
    }
    return 0;
}

// tc - O(1)
// sc - O(1)