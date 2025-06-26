#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long a, b, c; // a: buttons only Anna can press, b: buttons only Katie can press, c: buttons either can press
        cin >> a >> b >> c;
        
        // Check if the number of buttons that can be pressed by either is odd
        if (c % 2 == 1) // odd
        {
            // If c is odd, the player with more exclusive buttons will win
            if (b > a) // Katie has more exclusive buttons
                cout << "Second" << endl; // Katie wins
            else
                cout << "First" << endl; // Anna wins
        }
        else // even
        {
            // If c is even, the player with more exclusive buttons will win
            if (a > b) // Anna has more exclusive buttons
                cout << "First" << endl; // Anna wins
            else
                cout << "Second" << endl; // Katie wins
        }
    }
    return 0;
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
