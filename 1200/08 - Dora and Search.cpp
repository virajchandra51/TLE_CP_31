#include <bits/stdc++.h>

using namespace std;

bool isMinOrMax(int val, set<int> &segEle)
{
   if ((*segEle.begin()) == val)
      return true;

   if ((*segEle.rbegin()) == val)
      return true;

   return false;
} //? O(1)

int main()
{
   int t;
   cin >> t;

   while (t--)
   {
      int n;
      cin >> n;

      vector<int> arr(n);

      for (int i = 0; i < n; i++)
         cin >> arr[i]; //? O(N)

      set<int> segEle(arr.begin(), arr.end()); //? O(N log N)

      int i = 0, j = n - 1; //! l, r

      while (i < j)
      {
         if (isMinOrMax(arr[i], segEle)) //! al
         {
            segEle.erase(arr[i]); //? O(log N)
            i++;
            continue;
         }

         if (isMinOrMax(arr[j], segEle)) //! ar
         {
            segEle.erase(arr[j]); //? O(log N)
            j--;
            continue;
         }

         break;
      } //? O(N log N)

      if (i < j)
      {
         cout << (i + 1) << " " << (j + 1) << "\n";
      }
      else
      {
         cout << "-1\n";
      }
   }

   return 0;
}

//! Total time complexity : O(N log N)
//! Total space complexity : O(N)