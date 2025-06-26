#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Declare an integer t to store the number of test cases
    cin >> t; // Read the number of test cases from standard input
    while (t--) // Loop over each test case
    {
        long long n; // Declare a long long integer n to store the current integer for the test case
        cin >> n; // Read the integer n from standard input
        // Check if n is divisible by 3
        if (n % 3 == 0) // If n is divisible by 3, Vova wins
            cout << "Second" << endl; // Output "Second" indicating Vova wins
        else
            cout << "First" << endl; // Output "First" indicating Vanya wins
    }
    return 0; // Return 0 to indicate successful execution
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
