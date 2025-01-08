#include <bits/stdc++.h>
using namespace std;

// operation types:
// 1. Move Up and Right
// 2. Move Left

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int source_x, source_y, destination_x, destination_y;
        cin >> source_x >> source_y >> destination_x >> destination_y;

        // Step 1
        // If the destination y is to the bottom of the source y, 
        // then it is impossible to reach the destination.
        if (destination_y < source_y) // 1
        {
            cout << -1 << endl;
            continue;
        }

        // Step 2
        // If the destination y is to the up of the source y, 
        // then the minimum number of moves required is the difference
        // between the destination y and the source y, using operation type 1.
        int moves = destination_y - source_y; // 1

        // Step 3
        // Since operation type 1 is used to move up and right,
        // the source x will increase by the number of moves.
        source_x += moves;

        // Step 4
        // If the destination x is to the right of the source x,
        // then it is impossible to reach the destination.
        if (source_x < destination_x)
        {
            cout << -1 << endl;
            continue;
        }

        // If the destination x is to the left of the source x,
        // then the minimum number of moves required is the difference
        // between the source x and the destination x, using operation type 2.
        moves += (source_x - destination_x);
        cout << moves << endl;
    }
    return 0;
}

// tc - O(1)
// sc - O(1)