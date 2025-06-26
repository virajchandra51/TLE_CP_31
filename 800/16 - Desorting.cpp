#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        long long n;
        cin >> n; // Read the length of the array for the current test case
        long long a[n];
        for (int i = 0; i < n; i++) // Loop to read the array elements
            cin >> a[i];
        // Array input completed

        long long operations = INT_MAX; // Initialize operations to a large value
        for (int i = 0; i < n - 1; i++) // Iterate through the array to check for sorted order
        {
            if (a[i] <= a[i + 1]) // Check if the current pair is sorted
            {
                long long diff = a[i + 1] - a[i]; // Calculate the difference between consecutive elements
                long long required_operations = diff / 2 + 1; // Calculate the minimum operations needed to make them unsorted
                operations = min(operations, required_operations); // Update the minimum operations
            }
            else // If the array is already unsorted
                operations = 0; // No operations needed
        }

        cout << operations << endl; // Output the minimum operations needed for the current test case
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(500)
// Space Complexity (SC): O(n) = O(500)
