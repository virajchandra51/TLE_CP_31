#include <bits/stdc++.h>

using namespace std;

bool pf(long long val, int ind, int x, int mid)
{
    if (val + (1LL * (ind + 1) * (mid - 1)) <= x)
        return true;
    return false;

    //! if the cost of the ith packet is less than or equal to x for that day -> I can buy it
}

int binSearch(long long val, int ind, int x)
{
    int low = 1, high = 1e9 + 5;
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (pf(val, ind, x, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    } //? O(32)

    return ans;
} //? O(32)

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> cost(n); //! a
        for (int i = 0; i < n; i++) //? O(N)
            cin >> cost[i];

        sort(cost.begin(), cost.end()); //! b
        //? O(N log N)

        vector<long long> presum(n);

        presum[0] = cost[0];
        for (int i = 1; i < n; i++)
        {
            presum[i] = presum[i - 1] + cost[i];
        } //? O(N)

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += binSearch(presum[i], i, x); //? O(32)
        } //? O(N * 32)

        cout << ans << "\n";
    }

    return 0;
}

//! Total time complexity : O(N * 32 + N log N)
//! Total space complexity : O(N)