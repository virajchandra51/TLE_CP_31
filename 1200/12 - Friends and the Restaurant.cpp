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

      vector<int> x(n), y(n);

      for (int i = 0; i < n; i++)
         cin >> x[i]; //? O(N)

      for (int i = 0; i < n; i++)
         cin >> y[i]; //? O(N)

      multiset<int> ms;

      for (int i = 0; i < n; i++) //? O(N log N)
         ms.insert(y[i] - x[i]); //! val_i

      int ans = 0;

      while (ms.size() > 1)
      {
         int val1 = *ms.begin();
         ms.erase(ms.begin()); //? O(log N)

         auto it = ms.lower_bound(-val1); //! val2 + val1 >= 0
         //? O(log N)

         if (it == ms.end())
            continue;

         ans++;
         ms.erase(it); //? O(log N)
      } //? O(N log N)

      cout << ans << "\n";
   }

   return 0;
}

//! Total time complexity : O(N log N)
//! Total space complexity : O(N)