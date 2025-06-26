#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Declare a variable to store the number of test cases
    cin >> t; // Read the number of test cases
    while (t--) // Loop through each test case
    {
        long long n; // Declare a variable to store the size of the permutation
        cin >> n; // Read the size of the permutation
        long long a[n]; // Declare an array to store the permutation elements
        for (int i = 0; i < n; i++) // Loop to read the permutation elements
            cin >> a[i]; // Read each element of the permutation
        // input

        if (a[0] == 1) // Check if the first element of the permutation is 1
            cout << "YES" << endl; // If true, print "YES"
        else
            cout << "NO" << endl; // Otherwise, print "NO"
    }
    return 0; // Return 0 to indicate successful execution
}

// Time Complexity (TC): O(n) = O(10)
// Space Complexity (SC): O(n) = O(10)
