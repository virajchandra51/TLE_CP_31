#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        vector<long long> points_arr;
        points_arr.push_back(0);
        for (int i = 0; i < n; i++) // n
        {
            long long point;
            cin >> point;
            points_arr.push_back(point);
        }
        points_arr.push_back(x);
        n = points_arr.size();
        // inputs

        long long max_distance_between_points = INT_MIN;
        for (int i = 1; i < n; i++) // n
        {
            if (i == n - 1) // last point
                max_distance_between_points = 
                max(max_distance_between_points, 2 * (points_arr[i] - points_arr[i - 1]));
            else
                max_distance_between_points = 
                max(max_distance_between_points, points_arr[i] - points_arr[i - 1]);
        }
        cout << max_distance_between_points << endl;
    }
    return 0;
}

// tc - O(n) - O(50)
// sc - O(n)