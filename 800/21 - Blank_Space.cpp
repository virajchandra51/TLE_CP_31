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
        for (int i = 0; i < n; i++) // Loop to read n elements into the array
            cin >> a[i];
        // Input array is now populated

        long long count_of_zeroes = 0; // Variable to count consecutive zeroes
        long long maximum_length = 0; // Variable to store the maximum length of consecutive zeroes found
        for (int i = 0; i < n; i++) // Iterate over each element in the array
        {
            if (a[i] == 0)
                count_of_zeroes++; // Increment count if the current element is zero
            else
                count_of_zeroes = 0; // Reset count if the current element is not zero
            
            maximum_length = max(maximum_length, count_of_zeroes); // Update maximum length if current count is greater
        }
        cout << maximum_length << endl; // Output the maximum length of consecutive zeroes for this test case
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n)
