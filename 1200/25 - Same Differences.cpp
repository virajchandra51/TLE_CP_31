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

      vector<int> v(n); //! a

      for (int i = 0; i < n; i++)
      {
         cin >> v[i];

         v[i] -= i;
      } //? O(n)

      //! a -> a'

      map<long long, long long> freq;

      for (int i = 0; i < n; i++) //? O(N log N)
         freq[v[i]]++;

      long long ans = 0;

      for (auto &[val, count] : freq)
      {
         ans += ((count) * (count - 1)) / 2; //! x c 2
      }

      cout << ans << "\n";
   }

   return 0;
}

//! Total time complexity : O(N log N)
//! Total space complexity : O(N)