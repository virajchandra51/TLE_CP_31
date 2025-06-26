#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    // Read the number of elements in the array
    cin >> n;
    long long a[n];
    // Read the elements of the array
    for (int i = 0; i < n; i++) // Loop through each element
        cin >> a[i];
    // input

    long long minimum_operations = INT_MAX;
    // Initialize minimum_operations with a large value
    for (int i = 0; i < n; i++) // Loop through each element
        // Find the minimum absolute value in the array
        minimum_operations = min(minimum_operations, abs(a[i]));
    
    // Output the minimum number of operations needed
    cout << minimum_operations << endl;
    return 0;
}

// Time Complexity (TC): O(n)
// Space Complexity (SC): O(n)
