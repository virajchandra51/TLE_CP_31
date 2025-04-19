#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<int> v(m);
        for(int i = 0; i < m; i++) cin>>v[i]; //? O(m)

        sort(v.begin(), v.end()); //? O(m log m)

        vector<int> gaps;
        for(int i = 0; i < m-1; i++) {
            gaps.push_back(v[i+1] - v[i] - 1);
        } //? O(m)

        gaps.push_back(v[0] + n - v[m-1] - 1);

        sort(gaps.rbegin(), gaps.rend()); //? O(m log m)

        int numSaved = 0, numDays = 0;

        for(auto gap : gaps) {
            int currGap = gap - numDays * 2;
            if(currGap > 0) {
                numSaved++; //! left extremity of the current gap

                currGap -= 2;
                if(currGap > 0) numSaved += currGap; //! protecting the right extremity and all the elements in the range

                numDays += 2;
            }
        }

        cout<<(n - numSaved)<<"\n";
    }

    return 0;
}

//! Total time complexity : O(m log m)
//! Total space complexity : O(m)