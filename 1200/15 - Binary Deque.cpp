#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t;
   cin >> t;

   while (t--)
   {
      int n, s;
      cin >> n >> s;

      vector<int> v(n);

      for (int i = 0; i < n; i++)
         cin >> v[i]; //? O(N)

      int len = -1; //! maximum length of a subarray with sum = s.

      map<int, int> mp;

      mp[0] = -1;

      int sum = 0;

      for (int i = 0; i < n; i++)
      {
         sum += v[i];

         if (mp.count(sum - s))
         {
            len = max(len, i - mp[sum - s]);
         }

         if (!mp.count(sum))
         {
            mp[sum] = i; //? O(log N)
         }
      } //? O(N log N)

      if (len == -1)
      {
         cout << "-1\n";
      }
      else
      {
         cout << (n - len) << "\n";
      }
   }
}

//! Total time complexity : O(N log N)
//! Total space complexity : O(N)