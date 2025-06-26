#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Size of the array for the current test case
        cin >> n;
        long long a[n]; // Array to store the elements
        for (long long i = 0; i < n; i++) // Loop to input elements into the array
            cin >> a[i];
        // Input complete

        long long operations_count = 0; // Initialize the count of operations to 0

        for (long long i = 0; i < n - 1; i++) // Loop through the array to check adjacent elements
        {
            // Check if the current element and the next element have the same parity
            if ((a[i] % 2) == (a[i + 1] % 2))
                operations_count++; // Increment the operations count if they have the same parity
        }
        cout << operations_count << endl; // Output the number of operations required
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n) = O(100)
