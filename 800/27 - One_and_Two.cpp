#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Number of elements in the sequence
        cin >> n;
        long long a[n]; // Array to store the sequence
        for (long long i = 0; i < n; i++) // Reading the sequence elements
            cin >> a[i];
        // Inputs are now stored in array 'a'

        long long total_number_of_twos = 0; // Total count of '2's in the sequence
        long long current_number_of_twos = 0; // Count of '2's in the prefix

        // Calculate the total number of '2's in the sequence
        for (long long i = 0; i < n; i++) // Iterate through the sequence
        {
            if (a[i] == 2) // Check if the current element is '2'
                total_number_of_twos++; // Increment the total count of '2's
        } // End of counting total '2's

        long long ans = -1; // Variable to store the answer (smallest k)

        // Check for the smallest k where the condition is satisfied
        for (long long i = 0; i < n; i++) // Iterate through the sequence
        {
            if (a[i] == 2) // Check if the current element is '2'
                current_number_of_twos++; // Increment the prefix count of '2's

            // Check if the number of '2's in the prefix equals the number of '2's in the suffix
            if ((current_number_of_twos) == (total_number_of_twos - current_number_of_twos))
            {
                ans = i + 1; // Set the answer to the current index + 1 (1-based index)
                break; // Exit the loop as we found the smallest k
            }
        }

        cout << ans << endl; // Output the result for the current test case
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(1000)
// Space Complexity (SC): O(n) = O(1000)
