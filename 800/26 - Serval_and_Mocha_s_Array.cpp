#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Length of the array
        cin >> n;
        vector<long long> a(n); // Array to store the elements
        for (int i = 0; i < n; i++) // Loop to input elements into the array
            cin >> a[i];
        // Inputs are now stored in array 'a'

        int flag = 0; // Flag to check if a beautiful array can be formed
        for (int i = 0; i < n; i++) // Loop through each element
        {
            for (int j = i + 1; j < n; j++) // Loop to check pairs of elements
            {
                // Check if the gcd of any pair of elements is less than or equal to 2
                if (__gcd(a[i], a[j]) <= 2) // gcd calculation
                {
                    flag = 1; // Set flag to 1 if condition is met
                }
            }
        }

        // If no such pair is found, flag remains 0
        // If flag is 0, print "NO", else print "YES"
        if (flag == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

// Time Complexity (TC): O(n^2 * log2(min(a[i], a[j]))) = O(10^4 * 20) = O(2 * 10^5)
// Space Complexity (SC): O(n) = O(100)
