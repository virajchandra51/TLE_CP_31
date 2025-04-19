#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n, q;
   cin >> n >> q;

   vector<pair<int, int>> v(n, {0, 0});

   for (int i = 0; i < n; i++)
   {
      cin >> v[i].first;
   } //? O(n)

   pair<int, int> globalVal = {0, -1};

   long long sum = 0;

   for (int i = 0; i < n; i++) //? O(n)
      sum += v[i].first;

   for (int it = 1; it <= q; it++)
   {
      int x;
      cin >> x;

      if (x == 1)
      {
         int ind, val;
         cin >> ind >> val;

         ind--;

         if (v[ind].second > globalVal.second)
         {
            sum += (val - v[ind].first);
         }
         else
         {
            sum += (val - globalVal.first);
         }

         v[ind].first = val;
         v[ind].second = it;
      }
      else
      {
         int val;
         cin >> val;

         globalVal.first = val;
         globalVal.second = it;

         sum = (long long)(val)*n;
      }

      cout << sum << "\n";
   } //? O(q)

   return 0;
}

//! Total time complexity : O(n + q)
//! Total space complexity : O(n)