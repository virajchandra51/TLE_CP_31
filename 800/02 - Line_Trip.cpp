#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n, x; // n: number of gas stations, x: destination point
        cin >> n >> x;
        vector<long long> points_arr; // Array to store points including start, gas stations, and destination
        points_arr.push_back(0); // Start point
        for (int i = 0; i < n; i++) // Loop through each gas station
        {
            long long point;
            cin >> point; // Read each gas station point
            points_arr.push_back(point); // Add gas station point to the array
        }
        points_arr.push_back(x); // Add destination point
        n = points_arr.size(); // Update n to include start, gas stations, and destination
        
        long long max_distance_between_points = INT_MIN; // Variable to store the maximum distance between consecutive points
        for (int i = 1; i < n; i++) // Loop through each point
        {
            if (i == n - 1) // If it's the last point (destination)
                max_distance_between_points = 
                max(max_distance_between_points, 2 * (points_arr[i] - points_arr[i - 1])); // Consider the round trip distance
            else
                max_distance_between_points = 
                max(max_distance_between_points, points_arr[i] - points_arr[i - 1]); // Consider the one-way distance
        }
        cout << max_distance_between_points << endl; // Output the minimum tank capacity needed
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(50)
// Space Complexity (SC): O(n)
