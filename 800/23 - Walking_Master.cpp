#include <bits/stdc++.h>
using namespace std;

// operation types:
// 1. Move Up and Right
// 2. Move Left

int main()
{
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        int source_x, source_y, destination_x, destination_y;
        // Read the source and destination coordinates
        cin >> source_x >> source_y >> destination_x >> destination_y;

        // Step 1
        // If the destination y is below the source y, 
        // it is impossible to reach the destination.
        if (destination_y < source_y) // Check if destination y is below source y
        {
            cout << -1 << endl; // Output -1 indicating it's impossible
            continue; // Move to the next test case
        }

        // Step 2
        // Calculate the minimum number of moves required to match the y-coordinate
        // using operation type 1 (Move Up and Right).
        int moves = destination_y - source_y; // Calculate moves needed to match y-coordinate

        // Step 3
        // Adjust the source x-coordinate by the number of moves
        // since moving up and right also increases x.
        source_x += moves; // Update source x after moving up and right

        // Step 4
        // If the destination x is to the right of the updated source x,
        // it is impossible to reach the destination.
        if (source_x < destination_x) // Check if destination x is to the right
        {
            cout << -1 << endl; // Output -1 indicating it's impossible
            continue; // Move to the next test case
        }

        // If the destination x is to the left of the updated source x,
        // calculate the additional moves required using operation type 2 (Move Left).
        moves += (source_x - destination_x); // Add moves needed to match x-coordinate
        cout << moves << endl; // Output the total number of moves
    }
    return 0;
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
