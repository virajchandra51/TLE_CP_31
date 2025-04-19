#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<long long> &pmax, int n, int val)
{
   int low = 0, high = n - 1;
   int ans = -1; //! largest index for which aj <= ki

   while (low <= high)
   {
      int mid = (low + high) / 2;

      if (pmax[mid] <= val)
      {
         ans = mid;
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }

   return ans;
} //? O(log N)

int main()
{
   int t;
   cin >> t;

   while (t--)
   {
      int n, q;
      cin >> n >> q;

      vector<long long> steps(n), query(q);

      for (int i = 0; i < n; i++)
         cin >> steps[i]; //? O(N)

      for (int i = 0; i < q; i++)
         cin >> query[i]; //? O(N)

      vector<long long> pmax(n), psum(n);
      pmax[0] = steps[0];
      psum[0] = steps[0];

      for (int i = 1; i < n; i++)
      {
         pmax[i] = max(pmax[i - 1], steps[i]);
         psum[i] = psum[i - 1] + steps[i];
      } //? O(N)

      for (int i = 0; i < q; i++)
      { //? O(q)
         int val = query[i];

         int ind = binSearch(pmax, n, val); //? O(log N)

         if (ind == -1)
         {
            cout << "0 ";
         }
         else
         {
            cout << psum[ind] << " ";
         }
      } //? O(q log N)

      cout << "\n";
   }

   return 0;
}

//! Total time complexity : O(N + q log N)
//! Total space complexity : O(N + q)