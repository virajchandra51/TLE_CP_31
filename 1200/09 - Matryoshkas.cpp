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

      vector<int> v(n);

      for (int i = 0; i < n; i++)
         cin >> v[i]; //? O(N)

      map<int, int> cnt;

      for (int i = 0; i < n; i++)
         cnt[v[i]]++; //? O(N log N)

      int ans = 0; //! x

      for (auto &[ele, fre] : cnt) //! ele = .first, fre = .second
      {
         ans += max(0, cnt[ele] - cnt[ele - 1]);
      } //? O(N log N)

      cout << ans << "\n";
   }
}

//! Total time complexity : O(N log N)
//! Total space complexity : O(N)