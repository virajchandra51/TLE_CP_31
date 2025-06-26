#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases
    while (t--) // Loop through each test case
    {
        long long n; // Variable to store the number of teams
        cin >> n; // Read the number of teams
        long long a[n]; // Array to store the efficiency of n-1 teams
        for (long long i = 0; i < n - 1; i++) // Loop to read the efficiency of n-1 teams
            cin >> a[i]; // Read efficiency of each team
        // inputs

        long long sum = 0; // Variable to store the sum of efficiencies of n-1 teams
        for (long long i = 0; i < n - 1; i++) // Loop to calculate the sum of efficiencies
            sum += a[i]; // Add each team's efficiency to the sum

        cout << -1 * sum << endl; // Output the efficiency of the missing team, which is the negative of the sum
    }
    return 0; // Return 0 to indicate successful execution
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n) = O(100)
