#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases
    while (t--) // Loop over each test case
    {
        long long n; // Variable to store the length of permutation
        cin >> n; // Read the length of permutation
        long long a[n]; // Array to store the permutation 'a'
        for (int i = 0; i < n; i++) // Loop to read the permutation 'a'
            cin >> a[i]; // Read each element of permutation 'a'

        for (int i = 0; i < n; i++) // Loop to generate and print permutation 'b'
        {
            // Calculate and print each element of permutation 'b'
            // such that b[i] = n + 1 - a[i]
            cout << n + 1 - a[i] << " ";
        }
        cout << endl; // Print a newline after each test case
    }
    return 0; // Return 0 to indicate successful execution
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n) = O(100)
