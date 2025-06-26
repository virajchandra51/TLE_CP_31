#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        int n;
        cin >> n; // Read the number of cells in the current test case
        string s;
        cin >> s; // Read the string representing the row of cells
        
        // Initialize a flag to check for three continuous empty cells
        bool continuous_three_empty_cells = false;
        // Initialize a counter for the total number of empty cells
        int total_count_of_empty_cells = 0;

        // Iterate through the cells
        for (int i = 0; i < n; i++) // Loop through each cell
        {
            // Check if there are three continuous empty cells
            if (s[i] == '.' && i + 1 < n && s[i + 1] == '.' && i + 2 < n && s[i + 2] == '.')
            {
                continuous_three_empty_cells = true; // Set the flag to true if found
                break; // No need to check further if we found three continuous empty cells
            }
            // Count the number of empty cells
            if (s[i] == '.')
                total_count_of_empty_cells++;
        }

        // If there are three continuous empty cells, only 2 actions are needed
        if (continuous_three_empty_cells)
            cout << 2 << endl;
        else
            // Otherwise, the number of actions needed is equal to the number of empty cells
            cout << total_count_of_empty_cells << endl;
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n) = O(100)
