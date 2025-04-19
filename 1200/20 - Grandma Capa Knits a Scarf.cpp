#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ans = INT_MAX;

        for (char c = 'a'; c <= 'z'; c++)
        {
            int tmp = 0; //! minimum number of characters that were deleted if we could only delete c
            bool isPoss = true;

            int i = 0, j = n - 1;

            while (i < j)
            {
                if (s[i] == s[j])
                {
                    i++;
                    j--;
                    continue;
                }

                if (s[i] == c)
                {
                    tmp++;
                    i++;
                }
                else if (s[j] == c)
                {
                    tmp++;
                    j--;
                }
                else
                {
                    isPoss = false;
                    break;
                }
            } //? O(N)

            if (!isPoss)
                tmp = INT_MAX;

            ans = min(ans, tmp);
        } //? O(N * 26)

        if (ans == INT_MAX)
            ans = -1;

        cout << ans << "\n";
    }

    return 0;
}

//! Total time complexity : O(N * 26) = O(N)
//! Total space complexity : O(N)